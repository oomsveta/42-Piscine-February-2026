#!/bin/sh

: "${FT_NBR1:="\\'?\"\\\"'\\"}"
: "${FT_NBR2:=rcrdmddd}"

# : ${FT_NBR1:='\"\"!\"\"!\"\"!\"\"!\"\"!\"\"'}
# : ${FT_NBR2:=dcrcmcmooododmrrrmorcmcrmomo}

BASE_SYMBOLS="'\\\\\"?!mrdoc"
BASE_DIGITS="0123401234"
OUTPUT_SYMBOLS="gtaio luSnemf"

{
    echo "obase=13; ibase=5;"
    echo "$FT_NBR1 + $FT_NBR2" | tr "$BASE_SYMBOLS" "$BASE_DIGITS"
} | bc | tr "0123456789ABC" "$OUTPUT_SYMBOLS"
