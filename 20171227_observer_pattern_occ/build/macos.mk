CC=/brew/bin/g++
CCFLAGS=-Wall -std=c++11
LDFLAGS=-lstdc++fs -pthread
CCINCLUDE=-I./$(INCLUDE) -I./src
RM=rm
RMDIR=rm -rf

ifeq ($(DEBUG),1)
	CCFLAGS+=-g -O0
endif
