CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Wuninitialized -O0 -g -fsanitize=address,undefined -mcmodel=medium

TARGETS = words tfidf
SRCS = src/main.c         src/menu.c      src/input.c      src/display.c      src/token.c      src/djb2.c
HDRS = include/styling.h  include/menu.h  include/input.h  include/display.h  include/token.h  include/djb2.h

all: $(TARGETS)

words: words.c
	$(CC) $(CFLAGS) words.c -o words

tfidf: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o tfidf

clean:
	@rm -f $(TARGETS)

