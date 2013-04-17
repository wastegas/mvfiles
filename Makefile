CC=c++
CCFLAGS=-Wall
LDFLAGS=-lboost_system	-lboost_filesystem
BINDIR=build/

all:	$(BINDIR)/mvfiles

$(BINDIR)/mvfiles:	mvfiles.cpp
	$(CC)	$^	-o $@	$(LDFLAGS)	$(CCFLAGS)
