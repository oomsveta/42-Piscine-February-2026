#!/usr/bin/env bash

rm --force exo2.tar

# drwx--xr-x 2 XX XX XX Jun 1 20:47 test0
mkdir test0
chmod u=rwx,g=x,o=rx test0
touch --date 'Jun 1 20:47' test0

# -rwx--xr-- 1 XX XX 4 Jun 1 21:46 test1
truncate --size 4 test1
chmod u=rwx,g=x,o=r test1
touch --date 'Jun 1 21:46' test1

# dr-x---r-- 2 XX XX XX Jun 1 22:45 test2
mkdir test2
chmod u=rx,g=,o=r test2
touch --date 'Jun 1 22:45' test2

# -r-----r-- 2 XX XX 1 Jun 1 23:44 test3
truncate --size 1 test3
chmod u=r,g=,o=r test3
touch --date 'Jun 1 23:44' test3

# -rw-r----x 1 XX XX 2 Jun 1 23:43 test4
truncate --size 2 test4
chmod u=rw,g=r,o=x test4
touch --date 'Jun 1 23:43' test4

# -r-----r-- 2 XX XX 1 Jun 1 23:44 test5
ln test3 test5

# lrwxrwxrwx 1 XX XX 5 Jun 1 22:20 test6 -> test0
ln --symbolic test0 test6
touch --no-dereference --date 'Jun 1 22:20' test6

ls -l

tar --create --file exo2.tar test*
rm --force --recursive -- test*
