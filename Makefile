CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Wuninitialized -O0 -g -fsanitize=address,undefined -mcmodel=medium

TARGETS = tfidf

SRCS = $(wildcard src/*.c)
HDRS = $(wildcard include/*.h)

all: $(TARGETS)

tfidf: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o tfidf

clean:
	@rm -f $(TARGETS)

