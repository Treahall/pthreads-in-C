# Author: Trever Hall
# Date: 3/3/2022
# Description: Makefile for pthreads! 
CC = gcc
FLAGS = -pthread -Wall -Wextra

TARGET = pt pt-locks pt-tas pt-tatas

all: $(TARGET)

$(TARGET): %: %.c
	$(CC) $(FLAGS) $< -o $@ 

clean:
	rm $(TARGET)