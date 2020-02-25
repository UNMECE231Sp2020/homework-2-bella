FNS=complex.cpp
MAIN=main.cpp $(FNS)

all: 
	g++ $(MAIN) -o tests
clean:
	rm tests
