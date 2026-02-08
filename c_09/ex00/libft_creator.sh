#!/usr/bin/env bash

NAME=libft.a

CC=cc
CFLAGS='-Wall -Wextra -pedantic -O3'
AR=ar
RM=rm

SRC='ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c'

OBJ=''

for file in $SRC; do
    OBJ="$OBJ ${file%.c}.o"
done

$CC $CFLAGS -c -- $SRC

$AR rcs -- $NAME $OBJ

$RM -- $OBJ
