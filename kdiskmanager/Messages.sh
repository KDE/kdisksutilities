#! /usr/bin/env bash
$EXTRACTRC *.ui >> rc.cpp
$XGETTEXT `find . -name \*.cpp` -o $podir/kdiskmanager.pot

