#!/bin/sh

id --groups --name --zero -- $FT_USER | tr '\0' ',' | sed 's/,$//'
