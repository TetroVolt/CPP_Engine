# build an executable named program from source files

all: 

#makes the program without warnings
program:
	g++ -lSDL2 `sdl2-config --cflags --libs` -std=c++11 -o ./out/program *.o	
	
build: compileall
	g++ -W -Wall -lSDL2 `sdl2-config --cflags --libs`  -O0 -pedantic -std=c++11 -o ./out/program *.o

compileall: 
	g++ -W -Wall -lSDL2 `sdl2-config --cflags --libs`  -O0 -pedantic -std=c++11 -c `find src -name '*.cpp'`

clean:
	rm -rf *.o

run:
	echo "Running Program: "	
	./out/program

buildnclean: build clean

buildnrun: buildnclean run


