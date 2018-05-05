UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	include ./build/linux.mk
endif
ifeq ($(UNAME_S),Darwin)
	include ./build/macos.mk
endif

SRC=./src
INCLUDE=./include

all: occi occ observer

observer: main_observer.o Producer.o Observer.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^ $(LDFLAGS)

occi: main_occi.o BasicOccurrenceCounter.o FastOccurrenceCounter.o \
	InteractiveConsole.o CommonOccurrenceCounter.o Observer.o Producer.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^ $(LDFLAGS)

occ: main_occ.o BasicOccurrenceCounter.o FastOccurrenceCounter.o \
	InteractiveConsole.o CommonOccurrenceCounter.o Producer.o Observer.o
	@ $(CC) $(CCFLAGS) $(CCINCLUDE) -o $@ $^ $(LDFLAGS)

%.o: $(SRC)/%.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

main_observer.o: test/main_observer.cpp
	@ $(CC) -c $(CCFLAGS) $(CCINCLUDE) -o $@ $<

main_observer.o: $(INCLUDE)/errorCode.h $(INCLUDE)/Observer.h \
	$(INCLUDE)/Producer.h
main_occi.o: $(INCLUDE)/errorCode.h $(INCLUDE)/IOccurrenceCounter.h \
	$(INCLUDE)/InteractiveConsole.h $(INCLUDE)/FastOccurrenceCounter.h \
	$(INCLUDE)/CommonOccurrenceCounter.h
main_occ.o: $(INCLUDE)/errorCode.h $(INCLUDE)/IOccurrenceCounter.h \
	$(INCLUDE)/InteractiveConsole.h $(INCLUDE)/BasicOccurrenceCounter.h \
	$(INCLUDE)/CommonOccurrenceCounter.h
FastOccurrenceCounter.o: $(INCLUDE)/IOccurrenceCounter.h \
	$(INCLUDE)/FastOccurrenceCounter.h $(INCLUDE)/BasicOccurrenceCounter.h \
	$(INCLUDE)/HashTable.h $(INCLUDE)/Observer.h $(INCLUDE)/Producer.h
BasicOccurrenceCounter.o: $(INCLUDE)/IOccurrenceCounter.h \
	$(INCLUDE)/BasicOccurrenceCounter.h $(INCLUDE)/errorCode.h
CommonOccurrenceCounter.o:  $(INCLUDE)/BasicOccurrenceCounter.h \
	$(INCLUDE)/FastOccurrenceCounter.h $(INCLUDE)/CommonOccurrenceCounter.h
InteractiveConsole.o: $(INCLUDE)/InteractiveConsole.h $(INCLUDE)/errorCode.h
Producer.o: $(INCLUDE)/errorCode.h $(INCLUDE)/Observer.h $(INCLUDE)/Producer.h
Observer.o: $(INCLUDE)/Observer.h

clean:
	@ $(RMDIR) occ* observer *.o *~ *.dSYM $(INCLUDE)/*~ $(SRC)/*~
