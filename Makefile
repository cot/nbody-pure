$(CC) = gcc

all: nbody

debug: CC += -DDEBUG -g
debug: nbody

profile: CC += -DPROFILE -g -pg
profile: nbody

nbody: nbody.c proto.h library
	$(CC) nbody.c -lproto -lm	-W -Wall -ansi -pedantic -o nbody

library: proto.c
	$(CC) proto.c -fPIC -shared -o libproto.so	

clean:
	rm -rf *.o nbody 
