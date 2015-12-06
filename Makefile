OBJS=main.o
CFLAGS=
LIBS=
PROG=advent4

all:$(OBJS)
	gcc -o $(PROG) $(LIBS) $(OBJS)

%o:%c
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(PROG)
