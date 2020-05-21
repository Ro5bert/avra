#!/bin/sh

AVRA_BIN="../../src/avra"

for dir in */; do
	base="$(basename "${dir}")"
	sfile="${base}/${base}.asm"
    hexfile="${base}/${base}.hex"
    eepfile="${base}/${base}.eep.hex"
    printf "\nTesting ${base}\n"
	${AVRA_BIN} "${sfile}" > /dev/null || \
		(echo "AVRA had non-zero exit status"; exit 1)
    if [ ! -f "${hexfile}.expected" ]; then
		echo "No expected HEX file found"
	elif cmp "${hexfile}" "${hexfile}.expected"; then
		echo "HEX file ok"
	else
        printf "Different HEX file!\n\n"
        exit 1
    fi
    if [ ! -f "${eepfile}.expected" ]; then
		echo "No expected EEPROM file found"
	elif cmp "${eepfile}" "${eepfile}.expected"; then
		echo "EEPROM file ok"
    else
        printf "Different EEPROM file!\n\n"
        exit 1
    fi
    rm "${hexfile}" "${eepfile}" "${base}"/*.obj
done

printf "\nEverything ok!\n"
exit 0
