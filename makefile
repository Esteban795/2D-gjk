SRCDIR = src
HEADDIR = include
LIBDIR = ./src

CFLAGS = -W -Wall -Wextra -Wvla -fsanitize=address -lSDL2  -g -lm

DEPENDENCIES = $(SRCDIR)/vec2.c $(SRCDIR)/geometry.c $(SRCDIR)/polygon.c $(SRCDIR)/read_file.c $(SRCDIR)/gjk.c

build:
	gcc $(SRCDIR)/main.c -o ./bin/gjk $(DEPENDENCIES) $(CFLAGS)

run:
	./bin/gjk

clean:
	rm ./bin/gjk

all:
	make build
	make run