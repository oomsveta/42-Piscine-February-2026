#!/bin/sh

FT_LINE1="${FT_LINE1:=7}"
FT_LINE2="${FT_LINE2:=15}"

grep --invert-match '^#' /etc/passwd |              # cat the file, stripped of its comments
awk --field-separator : 'NR % 2 == 0 {print $1}' |  # on even lines only, print the first field, using : as the field separator
rev |                                               # print every line backwards
sort --reverse |                                    # sort lines in reverse alphabetical order
sed --quiet "$FT_LINE1,$FT_LINE2"p |                # keep only lines between FT_LINE1 and FT_LINE2
paste --serial --delimiters=, - |                   # join lines using a comma as the separator
sed 's/$/./'                                        # append a period
