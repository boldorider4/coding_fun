CC=/brew/Cellar/gcc/7.2.0/bin/g++-7
CCFLAGS=-Wall -std=c++11
CCINCLUDE=-I.
# CCINCLUDE_BOOST=-I$(HOME)/include/boost_gcc7
# CCLINK_BOOST=-L$(HOME)/lib/boost_gcc7 -lboost_program_options
ifeq ($(DEBUG),1)
        CCFLAGS+=-g -O0
endif

all: occ_bin

occ_bin:
	$(CC) $(CCFLAGS) $(CCINCLUDE) -o occ main.cpp

# occ_boost_bin:
# 	$(CC) $(CCFLAGS) $(CCLINK_BOOST) $(CCINCLUDE_BOOST) -o occ_boost main_boost.cpp

clean:
	rm -f occ* *~
