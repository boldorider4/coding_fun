CC=/brew/Cellar/gcc/7.2.0/bin/g++-7
CCFLAGS=-Wall -std=c++11

SRC=./src
INCLUDE=./include

CCINCLUDE=-I./$(INCLUDE) -I./src

LDFLAGS=-lstdc++fs

ifeq ($(DEBUG),1)
        CCFLAGS+=-g -O0
endif

all: occi occ

occi: main_occi.o OccurrenceCounter.o FastOccurrenceCounter.o InteractiveConsole.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) $(LDFLAGS) -o $@ $^

occ: main_occ.o OccurrenceCounter.o InteractiveConsole.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) $(LDFLAGS) -o $@ $^

%.o: $(SRC)/%.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

main_occi.o: $(INCLUDE)/errorCode.h $(INCLUDE)/InteractiveConsole.h $(INCLUDE)/FastOccurrenceCounter.h
main_occ.o: $(INCLUDE)/errorCode.h $(INCLUDE)/InteractiveConsole.h $(INCLUDE)/OccurrenceCounter.h
FasrOccurrenceCounter.o: $(INCLUDE)/FastOccurrenceCounter.h $(INCLUDE)/OccurrenceCounter.h $(SRC)/HashTable.h
OccurrenceCounter.o: $(INCLUDE)/OccurrenceCounter.h $(INCLUDE)/errorCode.h
InteractiveConsole.o: $(INCLUDE)/InteractiveConsole.h $(INCLUDE)/errorCode.h

clean:
	@ rm -rf occ* *.o *~ *.dSYM $(INCLUDE)/*~ $(SRC)/*~
