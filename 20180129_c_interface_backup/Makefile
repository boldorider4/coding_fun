CC=$(shell which gcc)
CCFLAGS=-Wall -std=c99
LDFLAGS=
SRC=.
INCLUDE=.
CCINCLUDE=-I$(INCLUDE)

ifeq ($(DEBUG),1)
	CCFLAGS+=-g -O0
endif


all: cintfc

cintfc: cintfc.o extern_impl.o
	$(CC) $(CCFLAGS) -o $@ $^

%.o: $(SRC)/%.c
	$(CC) -c $(CCFLAGS) -o $@ $<

cintfc.o: extern_impl.h
extern_impl.o: extern_impl.h

clean:
	rm -rf cintfc *.o *~ *.dSYM $(INCLUDE)/*~ $(SRC)/*~
