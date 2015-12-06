OBJS=main.o
CFLAGS=
LIBS=-lcrypto
PROG=advent4

all:$(OBJS)
	gcc -o $(PROG) $(LIBS) $(OBJS)

%o:%c
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(PROG)
