#!/bin/bash

CC=g++
CPPFLAGS="-I../include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

file=main

$CC ${file}.cpp $CPPFLAGS $LDFLAGS -o ${file}.exe
