#proto: proto.o nbody.o
#	gcc -o nbody proto.o nbody.o -lm 
#
#proto.o: proto.c
#	gcc -o proto.o -c proto.c -W -Wall -ansi -pedantic -lm
#
#nbody.o: nbody.c proto.h
#	gcc -o nbody.o -c nbody.c -W -Wall -ansi -pedantic
#

nbody: nbody.c proto.h library
	gcc nbody.c -lproto -lm	-W -Wall -ansi -pedantic -o nbody

library: proto.c
	gcc proto.c -fPIC -shared -o libproto.so	

clean:
	rm -rf *.o nbody 
