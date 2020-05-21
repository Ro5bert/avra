# Regression tests

Regression testing is done via the `runtests.sh` script, which has a zero exit
status if and only if all tests passed.
Each test gets it own folder (which should have a descriptive name).
Each test folder must contain either an executable called `test` or a source
file called `test.asm`.

* If the `test` executable exists, then it is executed inside the test
  directory and its return status indicates the result of the test (zero means
  success; non-zero means failure).
  The `test` executable can use the `AVRA` environment variable to determine
  the location of the AVRA executable.

* Otherwise, the `test.asm` source file is assembled.
  If assembly fails, then the test fails.
  Additionally, if `test.hex.expected` and `test.eep.hex.expected` exist in the
  test folder, then they are compared to the two output files from the
  assembler (`test.hex` and `test.eep.hex`, respectively);
  if the actual and expected outputs are not identical, then the test fails.

Of course, it's possible that output changes are normal, due to a new feature
or a bug fix. In these cases, expected hex files should be updated.

