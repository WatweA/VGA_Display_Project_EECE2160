main: main.o VGADisplay.o
	g++ main.o VGADisplay.o -o main

main.o: main.cpp
	g++ -c main.cpp -g -Wall

VGADisplay.o: VGADisplay.cpp
	g++ -c VGADisplay.cpp -g -Wall

clean:
	rm main main.o VGADisplay.o
