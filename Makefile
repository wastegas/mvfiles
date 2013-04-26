CC=clang++
CXXOPTS=-std=c++11
CXXFLAGS=$(CXXOPTS)
LDLIBS=-lboost_system	-lboost_filesystem
OBJDIR=obj
BINDIR=build
TARGET=$(BINDIR)/mvfiles

all:	$(TARGET)

debug:	CC+=	-DDEBUG -g
debug:	$(TARGET)
	
_OBJS=	mvfiles.o	\
	main.o	\

OBJS=	$(patsubst	%,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o:	%.cpp
	$(CC)	$(CXXFLAGS)	-c	-o	$@	$<

$(TARGET):	$(OBJS)
	$(CC)	$^	$(LDLIBS)	-o	$@

clean:
	rm	-f	$(OBJDIR)/*	$(TARGET)
