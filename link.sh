#! /bin/bash

source .env

if [[ ! -v KEYMAP ]]; then
    echo "KEYMAP not set - exiting"
    exit 1
fi

if [[ ! -f ./keymap.c ]]; then
    echo "keymap.c not found. Call ../link.sh from one of the keymap directories"
    exit 2
fi

ln -nfs $(pwd)/./keymap.c $KEYMAP/keymap.c
ln -nfs $(pwd)/../rules.mk $KEYMAP/rules.mk
ln -nfs $(pwd)/../mykeys.h $KEYMAP/mykeys.h
ln -nfs $(pwd)/../config.h $KEYMAP/config.h
ln -nfs $(pwd)/../mymacro.h $KEYMAP/mymacro.h
