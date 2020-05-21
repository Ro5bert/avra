#!/bin/sh

AVRA="../../src/avra"
tstcnt=0
failcnt=0
failed=0

fail() {
	echo "$1"
	failed=1
}

for dir in */; do
	base="$(basename "${dir}")"
	tstfile="${base}/test"
	srcfile="${base}/test.asm"
	hexfile="${base}/test.hex"
	eepfile="${base}/test.eep.hex"

	failed=0
	tstcnt=$((tstcnt+1))
	printf "\nTesting %s\n" "${base}"

	# First look for test executable.
	if [ -f "${tstfile}" ]; then
		if [ ! -x "${tstfile}" ]; then
			fail "${tstfile} is not executable"
		elif ! (cd "${base}" && AVRA="../${AVRA}" ./test); then
			fail "${tstfile} had non-zero exit status"
		fi
	# No test executable. Make sure test.asm exists.
	elif [ ! -f "${srcfile}" ]; then
		fail "Neither ${tstfile} nor ${srcfile} found"
	# test.asm exists; compile it.
	elif ! ${AVRA} "${srcfile}" > /dev/null; then
		fail "AVRA had non-zero exit status"
	# test.asm compiled successfully; check expected output.
	else
		# Check expected hex.
		if [ ! -f "${hexfile}.expected" ]; then
			echo "No expected HEX file found"
		elif cmp "${hexfile}" "${hexfile}.expected"; then
			echo "HEX file ok"
		else
			fail "Different HEX file"
		fi

		# Check expected eeprom hex.
		if [ ! -f "${eepfile}.expected" ]; then
			echo "No expected EEPROM file found"
		elif cmp "${eepfile}" "${eepfile}.expected"; then
			echo "EEPROM file ok"
		else
			fail "Different EEPROM file"
		fi

		rm "${hexfile}" "${eepfile}" "${base}"/*.obj
	fi

	if [ $failed -eq 1 ]; then
		echo "FAILED"
		failcnt=$((failcnt+1))
	else
		echo "PASSED"
	fi
done

printf "\n%d tests, %d failed\n\n" "$tstcnt" "$failcnt"
exit $((!!failcnt))
