CC=/usr/bin/g++-4.9
CCFLAGS=-Wall -std=c++11
CCINCLUDE=-I.
# CCINCLUDE_BOOST=-I$(HOME)/include/boost_gcc7
# CCLINK_BOOST=-L$(HOME)/lib/boost_gcc7 -lboost_program_options
ifeq ($(DEBUG),1)
        CCFLAGS+=-g -O0
endif

all: occ

occ: main.o FileParser.o CmdlParser.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^

# occ_boost_bin:
# 	@ $(CC) $(CCFLAGS) $(CCLINK_BOOST) $(CCINCLUDE_BOOST) -o occ_boost main_boost.cpp

main.o: main.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

FileParser.o: FileParser.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

CmdlParser.o: CmdlParser.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

FileParser.o: FileParser.h errorCode.h
CmdlParser.o: CmdlParser.h errorCode.h
main.o: FileParser.h CmdlParser.h errorCode.h

clean:
	@ rm -f occ* *.o *~
