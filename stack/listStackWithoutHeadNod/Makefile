#SRC = $(src)
SRC = ${wildcard *.c}

CC = gcc

C_INCLUDE_PAH += ./
C_FLAGS += -I${C_INCLUDE_PAH} ${C_HEADERS}

LIBS += pthread
#LIB_PATH += ./
#LD_FLAGS += -L${LIB_PATH} -l${LIBS}
LD_FLAGS += -l${LIBS}

all:
	${CC} -g -o test ${SRC} ${C_FLAGS} ${LD_FLAGS}

.PHONY:clean
clean:
	rm test