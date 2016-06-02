targets = ${shell ls *.c | sed 's/\.c//g'}

all:
	for i in $(targets);do gcc -o $$i $$i.c;done

clean:
	for i in $(targets);do rm -rf $$i;done
