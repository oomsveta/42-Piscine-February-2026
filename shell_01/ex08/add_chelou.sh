#!/bin/sh

# : "${FT_NBR1:="\\'?\"\\\"'\\"}"
# : "${FT_NBR2:=rcrdmddd}"

: "${FT_NBR1:="\\\"\\\"!\\\"\\\"!\\\"\\\"!\\\"\\\"!\\\"\\\"!\\\"\\\""}"
: "${FT_NBR2:=dcrcmcmooododmrrrmorcmcrmomo}"

BASE_SYMBOLS="'\\\\\"?!mrdoc"
BASE_DIGITS="0123401234"
CALCULATION=$(echo "$FT_NBR1 + $FT_NBR2" | tr "$BASE_SYMBOLS" "$BASE_DIGITS")
RESULT=$(echo "obase=13; ibase=5; $CALCULATION" | bc)
echo "$RESULT" | tr "0123456789ABC" "gtaio luSnemf"
