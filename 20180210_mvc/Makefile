UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	include linux.mk
endif

CCFLAGS=-Wall -std=c++11

SRC=./src
INCLUDE=./include

CCINCLUDE=-I./$(INCLUDE) -I./src

ifeq ($(DEBUG),1)
        CCFLAGS+=-g -O0
endif

all: mvc

mvc: main.o GuitarRepository.o CsvGuitarWriter.o GuitarController.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^ $(LDFLAGS)

%.o: $(SRC)/%.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

main.o: $(INCLUDE)/errorCode.h $(INCLUDE)/CsvGuitarWriter.h $(INCLUDE)/GuitarController.h
GuitarRepository.o: $(INCLUDE)/errorCode.h $(INCLUDE)/GuitarRepository.h $(INCLUDE)/Guitar.h
GuitarController.o: $(INCLUDE)/errorCode.h $(INCLUDE)/GuitarController.h $(INCLUDE)/GuitarFactory.h $(INCLUDE)/Guitar.h
CsvGuitarWriter.o: $(INCLUDE)/CsvGuitarWriter.h $(INCLUDE)/Guitar.h

clean:
	@ rm -rf mvc* *.o *~ *.dSYM $(INCLUDE)/*~ $(SRC)/*~
