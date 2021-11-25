install.packages('testit')
require(testit)
dyn.load('library.so')
r_files_dir <- 'out/R'
for(file in dir(r_files_dir)){
  source(sprintf('%s/%s', r_files_dir, file))
}
# some asserts...