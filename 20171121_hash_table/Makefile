CC=/usr/bin/g++-4.9
CCFLAGS=-Wall -std=c++11
CCINCLUDE=-I.
ifeq ($(DEBUG),1)
        CCFLAGS+=-g -O0
endif

all: hash_table

hash_table: main.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^

%.o: %.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

main.o: HashTable.h

clean:
	@ rm -rf hash_table* *.o *~
