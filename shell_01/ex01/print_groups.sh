#!/bin/sh

: "${FT_USER:=bocal}"

id --groups --name --zero -- $FT_USER | tr '\0' ',' | sed 's/,$//'
