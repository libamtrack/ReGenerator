# ReGenerator
R packagE Generator
## Requirements
* Python 3.8 or higher - for running scripts
* CMake - for compiliing and testing C examples

## Usage
Make sure that your C code compiles and passes the tests!

Terms:
* Target/output directory - the root directory of your package. By the end of using ReGenerator, its structure should look something like this:
```
out/   <- your target directory
├ DESCRIPTION
├ NAMESCPACE
├ R/
│ ├ a_file.R
│ ⋮
│ └ last_file.R
└ src/
  ├ a_file.c
  ├ a_file.h
  ├ a_file_wrappers.c
  ⋮
  └ last_file.<c|h>
```
* DESCRIPTION - the file containing metadata about your package ([explaination](https://r-pkgs.org/description.html) | [example](DESCRIPTION))
* NAMESPACE - this one has two definitions:
  - input file containing the list of functions you want to create wrappers for ([example](NAMESPACE))
  - package file with R directives related to importing dependencies and exporting public functions ([explaination](https://r-pkgs.org/namespace.html)

### 1. Files you have to create yourself
ReGenerator reauires you to create the input files NAMESPACAE and DESCRIPTION.

The syntax for the DESCRIPTION is the same as [when creating a package by hand](https://r-pkgs.org/description.html), except for the tags `##DATE##` and `##VERSION##`.

The syntax for NAMESPACE is very simple:
* Comments start with `#` and span the rest of the line
* All non-comment content should be the names of the functions, without ther return types or parameters, one per line
* A function name can be preceded by `noR:` (case-sensitive, without any whitespace after) to suppress exporting it by the package
* Any whitespace at the beginning or end of the line will be ignored

If your library links to other libraries (even libm or libpthread), make sure to also put files makevars and makevars.win into your target directory with the following declaration:
```
PKG_LIBS = <your linker options>
```

### 2. Using prepare.py
```
usage: prepare.py [-h] [-d [DESCRIPTION-file]] [-v version] [-o output_dir] sources_dir [sources_dir ...]

Prepares package files for building AFTER running header_parser.py

positional arguments:
  sources_dir           Directory which contains source files for your library

options:
  -h, --help            show this help message and exit
  -d [DESCRIPTION-file], --desc-path [DESCRIPTION-file]
                        The path to the DESCRIPTION file for your package, ./DESCRIPTION by default. The file may use
                        placeholder tags ##VERSION## and ##DATE## which will be replaced with current information.
                        Note that if the ##VERSION## tag is present, the version argument is required
  -v version, --version version
                        The version of your package
  -o output_dir, --out-dir output_dir
                        The directory to paste the files to, ./out/ by default
```
In the simplest case, given directory structure
```
./
├ DESCRIPTION
├ NAMESPACE
├ include/
│ └ ...
├ out/    <- your target directory
└ src/
  └ ...
```
you can simply use
```
python prepare.py include src
```
A more verbose usage would be something like
```
python prepare.py --desc-path ./DESCRIPTION --version 0.1 --out-dir ./out ./include ./src
```
Note that the former usage will only work if your DESCRIPTION file does NOT use the `##VERSION##` tag.

### 3. Using header_parser.py
```
usage: header_parser.py [-h] [-o output_dir] [-n namespace] [-l logfile] [-v] [-q] package_name infile [infile ...]

Create wrappers necessary to create an R package for functions declared in a header file(s)

positional arguments:
  package_name          The name of your package, must be the same as the name field in your DESCRIPTION
  infile                C header files (or glob patterns) to be parsed

options:
  -h, --help            show this help message and exit
  -o output_dir, --out-dir output_dir
                        directory to write wrappers to, (default ./out)
  -n namespace, --namespace namespace
                        path to project namespace file (default ./NAMESPACE)
  -l logfile, --log-file logfile
                        Redirect logging information to logfile instead of stderr
  -v, --verbose         Log more information, can be stacked up to 2 times. Concels out with -q
  -q, --quiet           Log less information, can be stacked up to 2 times. Cancels out with -v

Glob patterns supported by this script are:
    ? - matches any single character
    * - matches any string
    ** - matches any path recursively

For example, `?oo.txt` can match foo.txt and boo.txt, `*oo.txt` will additionally match kazoo.txt, and **oo.txt will match all of the above, as well as a/oo.txt and a/b/zoo.txt
```
In our simple case from the last point you could just use
```
python header_parser.py my_first_package 'src/**.h'
```
or
```
python header_parser.py --namespace ./NAMESPACE --out-dir ./out my_first_package './src/**.h'
```

### 4. Building and testing the package
The following steps need you to have the packages `roxygen2`, `pkgbuild` and `testit` installed as well as [rtools](https://cran.r-project.org/bin/windows/Rtools/rtools40.html) if you're using Windows.
In order to be built, your package first needs a proper NAMESPACE file. To do this, [go to your target directory in R](https://learn-r.org/r-tutorial/setwd-r.php) and call
```
roxygen2::roxygenise(load_code = 'source', roclets = 'namespace')
```
At this point, you can create a either a testing package using
```
roxygen2::roxygenise(roclets = c('collate', 'rd'))
```
or build and compress a production version using
```
pkgbuild::build(binary = TRUE, needs_compilation = TRUE)  # creates a platform-dependent binary distribution, or
pkgbuild::build(binary = FALSE)  # creates a platform-independent source distribution which requires client-side compilation
```

You can also test your package using the `testit` package. An example usage can be found [here](Rscripts/test.R).

### 5. Installing your built package
Assuming everything goes right, you should now have an archive (a zip file on Windows or a compressed tarball on Unix-like) that looks something like `my_first_package.zip`.

This file can be used to install the package on a different device (must be the same architecture if binary):
```
install.packages('my_first_package.zip')
library(my_first_package)
```
