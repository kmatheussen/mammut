#!/bin/sh

set -e
set -x

#cd juce_5_3_2/Builds/Linux
#CONFIG=Release make -j8
#cd ../../../

cd src

make -f Makefile.linux clean
make -f Makefile.linux -j8

unset PKG_CONFIG_PATH

make -f Makefile.macos clean
make -f Makefile.macos -j8
make -f Makefile.macos install

make -f Makefile.mingw clean
make -f Makefile.mingw -j8
make -f Makefile.mingw install

