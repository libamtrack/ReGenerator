install.packages('testit', repos='https://cloud.r-project.org/')
require(testit)
if(Sys.info()['sysname'] == 'Windows'{
	dyn.load('library.dll')
}
else{
	dyn.load('library.so')
}
r_files_dir <- 'out/R'
for(file in dir(r_files_dir)){
  source(sprintf('%s/%s', r_files_dir, file))
}
# Asserts for a few select functions
assert(no.params.int.return.function() %==% as.integer(-1))
assert(no.params.unsigned.int.return.function() %==% as.integer(10));
assert(abs(no.params.float.return.function() - 1.2) < 1e-5);
assert(abs(no.params.double.return.function() - 0.5) < 1e-5);
assert(no.params.bool.return.function() %==% TRUE);

assert(one.in.param.int.return.function(4) %==% as.integer(-4));
assert(one.in.param.unsigned.int.return.function(9) %==% as.integer(90));
assert(abs(one.in.param.float.return.function(6) - 7.2) < 1e-5);
assert(abs(one.in.param.double.return.function(8) - 4.0) < 1e-5);
assert(one.in.param.bool.return.function(10) %==% FALSE);
assert(one.in.param.bool.return.function(20) %==% TRUE);

assert(one.out.param.no.return.function() %==% as.integer(10))

assert(abs(one.in.one.out.param.no.return.function(5) - 7.5) < 1e-5)

ret <- one.in.two.out.params.no.return.function(4)
assert(abs(ret$param_out_one - 40) < 1e-5)
assert(abs(ret$param_out_two - 0.4) < 1e-5)

ret <- two.in.two.out.params.no.return.function(4, ' ')
assert(abs(ret$param_out_one - 72) < 1e-5)
assert(abs(ret$param_out_two - 32.4) < 1e-5)

ret <- two.in.three.out.params.no.return.function(11, ' ')
assert(abs(ret$param_out_one - 142) < 1e-5)
assert(abs(ret$param_out_two - 33.1) < 1e-5)
assert(ret$param_out_three %==% as.integer(37))

ret <- three.in.three.out.params.no.return.function(11, ' ', TRUE)
assert(abs(ret$param_out_one - 142) < 1e-5)
assert(abs(ret$param_out_two - 33.1) < 1e-5)
assert(ret$param_out_three %==% as.integer(37))

ret <- three.in.three.out.params.no.return.function(11, ' ', FALSE)
assert(abs(ret$param_out_one - 43) < 1e-5)
assert(abs(ret$param_out_two - 43) < 1e-5)
assert(ret$param_out_three %==% as.integer(43))

x <- (-10:-1) + 0.93
assert(one.table.in.no.out.params.int.return.function(x) %==% as.integer(-45));
assert(one.table.in.no.out.params.unsigned.int.return.function(x) %==% as.integer(45));
assert(abs(one.table.in.no.out.params.float.return.function(x) - (-45.7)) < 1e-5);
assert(abs(one.table.in.no.out.params.double.return.function(x) - (-45.7)) < 1e-5);
x <- x * (-3)
assert(one.table.in.no.out.params.bool.return.function(x) %==% FALSE);
assert(one.table.in.no.out.params.bool.return.function(x[1:3]) %==% TRUE)

assert(no.in.one.table.out.params.float.return.function(10) %==% rep(10.2, 10))
assert(one.param.in.one.table.out.no.return.function(4.5, 10) %==% rep(4.5, 10))
assert(one.table.in.one.table.out.params.no.return.function(x, 10) %==% as.integer(9:0 * 3))

y=1:10
z=10:1 * 2 + 8.21
assert(sum(abs(two.tables.in.one.table.out.params.no.return.function(x, y, 10) - z)) < 1e-5)
