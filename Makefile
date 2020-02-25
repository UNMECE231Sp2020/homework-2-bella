FNS=complex.cpp
MAIN=main.cpp $(FNS)

all: 
	gcc $(MAIN) -o tests
clean:
	rm tests
