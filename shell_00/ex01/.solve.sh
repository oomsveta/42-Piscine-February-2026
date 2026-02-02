#!/usr/bin/env bash

rm --force -- testShell00*

# -r--r-xr-x 1 XX XX 40 Jun 1 23:42 testShell00
truncate --size 40 testShell00
chmod u=r,g=rx,o=rx testShell00
touch --date 'Jun 1 23:42' testShell00

echo 'Obtained:'
ls -l
echo 'Expected:'
echo '-r--r-xr-x 1 XX XX 40 Jun 1 23:42 testShell00'

tar --create --file testShell00.tar testShell00
rm --force testShell00
