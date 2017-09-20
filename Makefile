PROGNAME=gmn
CFLAGS=-Wall
OBJS=main
all: compile

compile: $(OBJS).o
	gcc $^ -o $(PROGNAME)
		
$(OBJS).o: $(OBJS).c
	gcc -c $(CFLAGS) $^

clean:
	rm -f gmn main.o

install:
	install gmn /usr/local/bin
