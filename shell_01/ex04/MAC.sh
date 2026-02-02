#!/bin/sh

ifconfig | grep --extended-regexp --only-matching '([[:xdigit:]]{2}:){5}([[:xdigit:]]{2})'
