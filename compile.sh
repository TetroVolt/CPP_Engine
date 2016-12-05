#!/bin/bash

#g++ -W -Wall `sdl2-config --cflags --libs` -lSDL_ttf -O0 -pedantic -std=c++11 -o ./out/program ./src/*.cpp

#g++ -W -Wall `sdl2-config --cflags --libs` -O0 -pedantic -std=c++11 -o ./out/program ./src/*.cpp

#                                                                                           V this piece looks for all cpp files
g++ -W -Wall -lSDL2 `sdl2-config --cflags --libs`  -O0 -pedantic -std=c++11 -o ./out/program `find src -name '*.cpp'`
