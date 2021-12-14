install.packages('roxygen2', repos='https://cloud.r-project.org/')
library(roxygen2)
setwd('out')
# build NAMESPACE file
roxygenise(load_code = 'source', roclets = 'namespace')
# build dev package
roxygenise(roclets = c('collate', 'rd'))