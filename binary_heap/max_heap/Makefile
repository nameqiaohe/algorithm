CC = gcc
CFLAGS += -g -Wall	-lpthread

SRC = ${shell ls *.c}

# Makefile 内置变量
DIR = $(PWD)
#DIR = ${shell pwd}	# 或者用shell命令获取当前路径
BIN=bin
BIN_PATH = $(DIR)/$(BIN)

include env.mk

all:

ifeq ("bin", $(wildcard $(BIN)))	# if语句的前边不能用tab，否则会报错 Syntax error: word unexpected (expecting ")")
	@echo "already has the directory : bin"
else
	mkdir -p bin
endif

	@echo "compiling ..."
#for i in $(TARGET); do $(CC) $$i.c $(GDBFLAG) -o $(BIN_PATH)/$$i $(CFLAGS); done
	$(CC) $(SRC) -o $(BIN_PATH)/test

.PHONY:all clean
clean:
	@echo "clean up"
#for i in $(TARGET); do rm -rf $(BIN_PATH)/$$i; done
	rm -rf $(BIN_PATH)

