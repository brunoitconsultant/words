CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Wuninitialized -O0 -g -fsanitize=address,undefined -mcmodel=medium

TARGETS = \
        words \
        tfidf

SRCS = $(wildcard src/*.c)
HDRS = $(wildcard include/*.h)

all: $(TARGETS)

words: words.c
	$(CC) $(CFLAGS) words.c -o words

tfidf: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o tfidf

clean:
	@rm -f $(TARGETS)

