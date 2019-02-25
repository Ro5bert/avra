#!/bin/bash

AVRA_BIN="../../src/avra"

for sfile in *.asm; do
    hexfile="$(basename $sfile .asm).hex"
    eepfile="$(basename $sfile .asm).eep.hex"
    echo "Processing ${sfile} ${hexfile}"
    ${AVRA_BIN} ${sfile} > /dev/null
    if cmp ${hexfile} ${hexfile}.expected; then
        echo "HEX file ok"
    else
        echo "Different HEX file"
        exit 1
    fi
    if cmp ${eepfile} ${eepfile}.expected; then
        echo "EEPROM file ok"
    else
        echo "Different EEPROM file"
        exit 1
    fi
    rm ${hexfile} ${eepfile} *.obj
done

echo "Everything ok!"
exit 0
