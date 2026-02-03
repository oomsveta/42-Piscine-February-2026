#!/bin/sh

: "${FT_LINE1:=7}"
: "${FT_LINE2:=15}"

# cat the file, stripping comments
grep --invert-match '^#' /etc/passwd |
# print the first field of even-numbered lines, using ':' as the separator
awk -F: 'NR % 2 == 0 {print $1}' |
# reverse the characters of each line
rev |
# sort lines in reverse alphabetical order
sort --reverse |
# only keep lines between FT_LINE1 and FT_LINE2
sed --quiet "$FT_LINE1,$FT_LINE2"p |
# join lines using a comma as the separator
paste --serial --delimiters=, - |
# replace commas with comma-spaces and append a trailing dot
sed 's/,/, /g; s/.$/&./'
