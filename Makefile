CFLAGS=-Wall

INCLUDES=-I$(saclib)/include

EXTLIBS=-lreadline
EXTLIBSOPT=$(saclib)/lib/saclibo.a $(EXTLIBS)
EXTLIBSDEB=$(saclib)/lib/saclibd.a $(EXTLIBS)

CFLAGS=-Wall
CFLAGSDEB=-g $(CFLAGS)
CFLAGSOPT=-O4 $(CFLAGS)

EXE=main

DEPENDENCIES=\
read_input.o\
write_output.o\
stratify.o\
main.o

all: opt deb

# optimised
opt:override CFLAGS = $(CFLAGSOPT)
opt:$(DEPENDENCIES)
	$(CC) $(INCLUDES) $(CFLAGSOPT) -o $(EXE) *.o $(EXTLIBSOPT)

# debug
opt:override CFLAGS = $(CFLAGSDEB)
deb:$(DEPENDENCIES)
	$(CC) $(INCLUDES) $(CFLAGSDEB) -o $(EXE) *.o $(EXTLIBSDEB)

# clean
clean:
	rm -f *.o main

# objects
%.o:%.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<
