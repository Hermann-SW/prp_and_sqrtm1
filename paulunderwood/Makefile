CFLAGS = -I../p95v3019b14/gwnum -O3
LDFLAGS = -lgmp -L../p95v3019b14/gwnum -l:gwnum.a -lm -lpthread

all: prg.o gw_utility.o
	gcc -o prg prg.o gw_utility.o $(LDFLAGS)
	echo 1001111 | ./prg
	echo "n=1001111;e=n-2;b=3;lift(Mod(b,n)^e)" | gp -q

gw_utility.o: gw_utility.c
	gcc -c $< $(CFLAGS)

prg.o: prg.c 
	gcc -c $< $(CFLAGS)

clean:
	rm -f prg *.o
