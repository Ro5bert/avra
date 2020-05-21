# Regression tests

Each test gets it own folder, which must contain an `x.asm` file, where `x` is
the name of the folder.
Each test folder can also optionally contain `x.hex.expected` and/or
`x.eep.hex.expected`.
When `runtests.sh` is executed, it runs `avra` on each source file and compares
the result with the expected results (if they exists).
`runtests.sh` fails if and only if the expected results are given and they are
different than the actual results, or if `avra` has a non-zero exit status.

Of course, it's possible that output changes are normal, due to a new feature
or a bug fix. In these cases, expected hex files should be updated.

