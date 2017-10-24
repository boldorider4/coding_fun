CXX = /usr/bin/g++
CXXFLAGS = -Wall --std=c++11
SOURCES = ./zombie.cpp

zombie.o:
	$(CXX) $(CXXFLAGS) -o ./zombie -I. $(SOURCES)

all: zombie.o

clean:
	rm -rf zombie.o *~
