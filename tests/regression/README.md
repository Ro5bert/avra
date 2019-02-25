# Regression tests

In this folder, we test regression by having a bunch of example source file
along with their expected HEX result. `runtests.sh` runs `avra` on each source
file and compares the result with the expected results. Fails if different.

Of course, it's possible that output changes are normal, due to a new feature
or a bug fix. In these cases, expected hex files should be updated.
