assign1: assign2.c pslibrary.c
	cc -o assign2 assign2.c pslibrary.c
all:
	cc -o runall pslibrary.c runall.c 
quizrun:
	./assign2 3 8 7 3 6 3 2
	./assign2 3 8 7 3 6 7 2
	./assign2 4 8 7 3 6 1 2
	./assign2 0 3 3 4 2 1 2
	./assign2 0 3 2 3 2 1 2
	./assign2 3 5 2 5 4 1 1
	./assign2 3 4 1 7 3 7 2
	./assign2 3 4 2 5 3 2 2
	./assign2 3 3 5 5 2 3 5
	./assign2 3 1 1 4 1 1 1
	./assign2 0 1 1 1 1 1 1
	./assign2 0 1 3 1 3 1 1
clean:
	rm -f assign2 *.o
