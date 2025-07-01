all: compile run

compile:
	gcc -I ./include/ -o ./lib/BuzDeviGezegen.o -c ./src/BuzDeviGezegen.c
	gcc -I ./include/ -o ./lib/CuceGezegen.o -c ./src/CuceGezegen.c
	gcc -I ./include/ -o ./lib/DosyaOkuma.o -c ./src/DosyaOkuma.c
	gcc -I ./include/ -o ./lib/GazDeviGezegen.o -c ./src/GazDeviGezegen.c
	gcc -I ./include/ -o ./lib/Gezen.o -c ./src/Gezegen.c
	gcc -I ./include/ -o ./lib/KayacGezegen.o -c ./src/KayacGezegen.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisii.c
	gcc -I ./include/ -o ./lib/UzayAraci.o -c ./src/UzayAraci.c
	gcc -I ./include/ -o ./lib/Zaman.o -c ./src/Zaman.c
	gcc -I ./include/ -o ./lib/Simulasyon.o -c ./src/Simulasyon.c
	gcc -I ./include/ -o ./lib/main.o -c ./src/main.c
	gcc -I ./include/ -o ./bin/Simulasyon \
		./lib/BuzDeviGezegen.o \
		./lib/CuceGezegen.o \
		./lib/DosyaOkuma.o \
		./lib/GazDeviGezegen.o \
		./lib/Gezen.o \
		./lib/KayacGezegen.o \
		./lib/Kisi.o \
		./lib/UzayAraci.o \
		./lib/Zaman.o \
		./lib/Simulasyon.o \
		./lib/main.o

run:
	./bin/Simulasyon