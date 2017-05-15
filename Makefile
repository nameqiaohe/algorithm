targets = ${shell ls *.c | sed 's/\.c//g'}
CFLAGS = -Wall -g

all:
	for i in $(targets);do gcc -o $$i $$i.c $(CFLAGS);done

clean:
	for i in $(targets);do rm -rf $$i;done
