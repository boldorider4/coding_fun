CC=/brew/Cellar/gcc/7.2.0/bin/g++-7
CCFLAGS=-Wall -std=c++11
CCINCLUDE=-I.
# CCINCLUDE_BOOST=-I$(HOME)/include/boost_gcc7
# CCLINK_BOOST=-L$(HOME)/lib/boost_gcc7 -lboost_program_options
ifeq ($(DEBUG),1)
        CCFLAGS+=-g -O0
endif

all: occ

occ: main.o fileParser.o cmdlParser.o
	$(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^

# occ_boost_bin:
# 	$(CC) $(CCFLAGS) $(CCLINK_BOOST) $(CCINCLUDE_BOOST) -o occ_boost main_boost.cpp

main.o: main.cpp
	$(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

fileParser.o: fileParser.cpp
	$(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

cmdlParser.o: cmdlParser.cpp
	$(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

fileParser.o: fileParser.h errorCode.h
cmdlParser.o: cmdlParser.h errorCode.h
main.o: fileParser.h cmdlParser.h errorCode.h

clean:
	rm -f occ* *.o *~
