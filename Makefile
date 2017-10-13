all: caixas.o
	g++ -o caixas caixas.o

clean:
	rm *.o caixas

