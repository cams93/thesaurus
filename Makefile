all:
	gcc -o hashset hashsettest.c hashset.c vector.c
test:
	./hashset
vector:
	gcc -o vectortest vectortest.c vector.c
	./vectortest
