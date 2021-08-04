CFLAGS=-Wall

INCLUDES=-I$(saclib)/include
EXTLIBS=$(saclib)/lib/saclibo.a
EXE=main

DEPENDENCIES=\
read_input.o\
main.o


all: opt deb

# optimised
opt:$(DEPENDENCIES)
	$(CC) $(INCLUDES) $(CFLAGS) -O4 -o $(EXE) *.o $(EXTLIBS)

# debug
deb:$(DEPENDENCIES)
	$(CC) $(INCLUDES) $(CFLAGS) -g -o $(EXE) *.o $(EXTLIBS)

# clean
clean:
	rm -f *.o main

# objects
%.o:%.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<
