CC=$(shell which g++)
CCFLAGS=-Wall
CCFLAGS+=-std=c++14

SRC=.
CCINCLUDE= -I.

ifeq ($(DEBUG),1)
        CCFLAGS+=-g -O0
endif

all: cast

cast: main.o
	$(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^

%.o: $(SRC)/%.cpp
	$(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

clean:
	rm -rf cast* *.o *~ *.dSYM $(SRC)/*~
