#!/bin/sh

# FT_NBR1="\\'?\"\\\"'\\"
# FT_NBR2=rcrdmddd

# FT_NBR1='\"\"!\"\"!\"\"!\"\"!\"\"!\"\"'
# FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo

echo "obase=13; ibase=5; $(echo $FT_NBR1 + $FT_NBR2 | tr "'\\\\\"?!mrdoc" 0123401234)" | bc | tr 0123456789ABC 'gtaio luSnemf'
