# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -std=c11 -g

# Target executable
TARGET = chess

# Source files
SRCS = main.c board.c attacks.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c board.h bit_utils.h attacks.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean