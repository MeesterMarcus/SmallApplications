all: ieee

ieee: ieee.h ieee.c ieee-library.c
	gcc -o ieee ieee.c ieee-library.c

clean:
	rm -rf ieee ieee.out

run0:
	./ieee

run1:
	./ieee 500

run2:
	./ieee 0x6e2

run3:
	./ieee 0

run4:
	./ieee 50

run5:
	./ieee 0xa17

run6:
	./ieee 0xf80

run7:
	./ieee 0xfff

runall:
	./ieee 500
	./ieee 0x6e2
	./ieee 0
	./ieee 50
	./ieee 0xa17
	./ieee 0xf80
	./ieee 0xfff

