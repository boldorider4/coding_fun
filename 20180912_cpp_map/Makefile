UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	include ./build/linux.mk
endif
ifeq ($(UNAME_S),Darwin)
	include ./build/macos.mk
endif

CCFLAGS=-Wall -std=c++14

SRC=.
INCLUDE=.

CCINCLUDE=-I./$(INCLUDE) -I./$(SRC)

LDFLAGS=

ifeq ($(DEBUG),1)
	CCFLAGS+=-g -O0
endif

all: map

map: map_main.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^ $(LDFLAGS)

%.o: $(SRC)/%.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

clean:
	@ rm -rf map *.o *~ *.dSYM $(INCLUDE)/*~ $(SRC)/*~
