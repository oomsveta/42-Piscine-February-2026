#!/bin/sh

ls -l | sed --quiet '1~2p'
