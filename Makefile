CFLAGS=-Wall

INCLUDES=-I$(saclib)/include
EXTLIBS=$(saclib)/lib/saclibo.a
EXE=main

all: opt deb

# optimised
opt:*.o
	$(CC) $(INCLUDES) $(CFLAGS) -O4 -o $(EXE) *.o $(EXTLIBS)

# debug
deb:*.o
	$(CC) $(INCLUDES) $(CFLAGS) -g -o $(EXE) *.o $(EXTLIBS)

# clean
clean:
	rm -f *.o main

# objects
%.o:%.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<
