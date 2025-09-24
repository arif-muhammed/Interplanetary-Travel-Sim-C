all: derle calistir

derle:
	gcc -I ./include/ -c ./src/Gezegen.c -o ./lib/Gezegen.o
	gcc -I ./include/ -c ./src/GazDeviGezegen.c -o ./lib/GazDeviGezegen.o
	gcc -I ./include/ -c ./src/BuzDeviGezegen.c -o ./lib/BuzDeviGezegen.o
	gcc -I ./include/ -c ./src/CuceGezegen.c -o ./lib/CuceGezegen.o
	gcc -I ./include/ -c ./src/KayacGezegen.c -o ./lib/KayacGezegen.o
	gcc -I ./include/ -c ./src/Kisi.c -o ./lib/Kisi.o
	gcc -I ./include/ -c ./src/UzayAraci.c -o ./lib/UzayAraci.o
	gcc -I ./include/ -c ./src/Zaman.c -o ./lib/Zaman.o
	gcc -I ./include/ -c ./src/DosyaOkuma.c -o ./lib/DosyaOkuma.o
	gcc -I ./include/ -c ./src/Simulasyon.c -o ./lib/Simulasyon.o
	gcc -I ./include/ -c ./src/Main.c -o ./lib/Main.o
	gcc -I ./include/ -c ./src/Yazdirma.c -o ./lib/Yazdirma.o


	gcc -o ./bin/program ./lib/Gezegen.o ./lib/GazDeviGezegen.o ./lib/BuzDeviGezegen.o ./lib/CuceGezegen.o ./lib/KayacGezegen.o ./lib/Kisi.o ./lib/UzayAraci.o ./lib/Zaman.o ./lib/DosyaOkuma.o ./lib/Simulasyon.o ./lib/Main.o ./lib/print_utils.o

calistir:
	./bin/program
