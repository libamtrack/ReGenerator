import argparse
import datetime
import logging
from glob import glob
from pathlib import Path
from shutil import copy


def main():
    parser = argparse.ArgumentParser(
        description='Prepares package files for building'
    )
    parser.add_argument(
        'sources_dir', nargs='+',
        help='Directory which contains source files for your library',
        type=Path
    )
    parser.add_argument(
        '-d', '-desc-path',
        dest='desc_file', nargs='?',
        metavar='DESCRIPTION-file',
        help='''The path to the DESCRIPTION file for your package,
            ./DESCRIPTION by default. The file may use placeholder
            tags ##VERSION## and ##DATE## which will be replaced with
            current information. Note that if the ##VERSION## tag is
            present, the version argument is required''',
        default='./DESCRIPTION',
        type=Path
    )
    parser.add_argument(
        '-v', '--version', metavar='version',
        help='The version of your package',
        default=''
    )
    parser.add_argument(
        '-o', '--out-dir', dest='out_dir', metavar='output_dir',
        help='The directory to paste the files to, ./out/ by default',
        default='./out',
        type=Path
    )

    args = parser.parse_args()
    out_dir: Path = args.out_dir
    desc_file: Path = args.desc_file
    version: str = args.version
    src_dir: list[Path] = args.sources_dir

    (out_dir / 'src').mkdir(parents=True, exist_ok=True)
    try:
        with open(desc_file, 'r') as fin:
            description = fin.read()
    except IOError as e:
        logging.critical("Couldn't open DESCRIPTION file: {}"
                         .format(e))

    try:
        if '##VERSION##' in description and version == '':
            raise RuntimeError(
                'Version argument is required with ##VERSION## tag'
            )
        description = (
            description.replace('##VERSION##', version)
            .replace('##DATE##', datetime.date.today().isoformat())
        )
        with open(out_dir / 'DESCRIPTION', 'w') as fout:
            fout.write(description)
    except Exception as e:
        logging.critical("Couldn't write DESCRIPTION file: {}"
                         .format(e))

    out_dir /= 'src'
    try:
        for directory in src_dir:
            for file in glob(str(directory / '**.c')) + glob(str(directory / '**.h')):
                copy(file, out_dir)
    except OSError as e:
        logging.critical("Couldn't copy source files (erred on {}): {}"
                         .format(file, e))


if __name__ == '__main__':
    main()
