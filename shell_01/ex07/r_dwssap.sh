#!/bin/sh

: "${FT_LINE1:=7}"
: "${FT_LINE2:=15}"

# cat the file, stripped of its comments
grep --invert-match '^#' /etc/passwd |
# on even lines only, print the first field, using : as the field separator
awk --field-separator : 'NR % 2 == 0 {print $1}' |
# print every line backwards
rev |
# sort lines in reverse alphabetical order
sort --reverse |
# only keep lines between FT_LINE1 and FT_LINE2
sed --quiet "$FT_LINE1,$FT_LINE2"p |
# join lines using a comma as the separator
paste --serial --delimiters=, - |
# add spaces after commas
sed 's/,/, /g' |
# append a period
sed 's/.$/&./'
