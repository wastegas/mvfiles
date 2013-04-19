CC=c++
CCFLAGS=-D NDEBUG	-Wall
LDFLAGS=-lboost_system	-lboost_filesystem
BINDIR=build
TARGET=$(BINDIR)/mvfiles

.PHONY:	all

all:	$(TARGET)

$(TARGET):	mvfiles.cpp
	$(CC)	$^	-o $@	$(LDFLAGS)	$(CCFLAGS)

clean:
	rm build/*
