all: compile run

compile:
	gcc -I ./include -o ./lib/alive.o -c ./src/alive.c 
	gcc -I ./include -o ./lib/plant.o -c ./src/plant.c 
	gcc -I ./include -o ./lib/beetle.o -c ./src/beetle.c 
	gcc -I ./include -o ./lib/fly.o -c ./src/fly.c 
	gcc -I ./include -o ./lib/flea.o -c ./src/flea.c 
	gcc -I ./include -o ./lib/habitat.o -c ./src/habitat.c 
	gcc -I ./include -o ./bin/main ./lib/alive.o ./lib/plant.o ./lib/beetle.o ./lib/fly.o ./lib/flea.o ./lib/habitat.o ./src/main.c

run:
	./bin/main
