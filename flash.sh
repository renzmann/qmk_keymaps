#! /bin/bash

KEYMAP=$1
FLASH_DIR=$2

ln -nfs $(pwd)/$KEYMAP/keymap.c $FLASH_DIR/keymap.c
ln -nfs $(pwd)/rules.mk $FLASH_DIR/rules.mk
ln -nfs $(pwd)/mykeys.h $FLASH_DIR/mykeys.h
ln -nfs $(pwd)/config.h $FLASH_DIR/config.h
ln -nfs $(pwd)/mymacro.h $FLASH_DIR/mymacro.h

cd $FLASH_DIR/../../../..
source .venv/bin/activate

cd $FLASH_DIR
qmk flash
