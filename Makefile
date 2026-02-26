CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS = -lm
PROGRAMS = external_test user_input

all: $(PROGRAMS)
	external_test user_input built

external_test: src/astro_math.c src/external_test.c
	$(CC) $(CFLAGS) src/astro_math.c src/external_test.c -o $@ $(LDFLAGS)

user_input: src/astro_math.c src/user_input.c
	$(CC) $(CFLAGS) src/astro_math.c src/user_input.c -o $@ $(LDFLAGS)

install: $(PROGRAMS)
	sudo install -m 755 $(PROGRAMS) /usr/local/bin/

clean:
	rm -f $(PROGRAMS)

.PHONY: all install clean
