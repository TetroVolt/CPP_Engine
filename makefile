# build an executable named program from source files

#all: program
#	g++ -W -Wall -lSDL2 `sdl2-config --cflags --libs`  -O0 -pedantic -std=c++11 -o ./out/program `find src -name '*.cpp'`

#clean:
#	$(RM) program

all: program

program: compileall
	g++ -W -Wall -lSDL2 `sdl2-config --cflags --libs`  -O0 -pedantic -std=c++11 -o ./out/program *.o

compileall:
	g++ -W -Wall -lSDL2 `sdl2-config --cflags --libs`  -O0 -pedantic -std=c++11 -c `find src -name '*.cpp'`

clean:
	rm -rf *.o
