CC=c++	-std=c++11
CXXOPTS=-DNDEBUG	-Wall
CXXFLAGS=$(CXXOPTS)
LDLIBS=-lboost_system	-lboost_filesystem
OBJDIR=obj
BINDIR=build
TARGET=$(BINDIR)/mvfiles

all:	$(TARGET)

_OBJS=	main.o	\
	mvfiles.o	\

OBJS=	$(patsubst	%,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o:	%.cpp
	$(CC)	$(CXXFLAGS)	-c	-o	$@	$<

$(TARGET):	$(OBJS)
	$(CC)	$^	$(LDLIBS)	-o	$@

clean:
	rm	-f	$(OBJDIR)/*	$(TARGET)
