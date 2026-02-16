CCFLAGS = -Ip95v3019b14/gwnum -O3
LDDFLAGS = -lgmp -lgmpxx -Lp95v3019b14/gwnum -l:gwnum.a -lm -lpthread

all: p95v3019b14 paulunderwood/gw_utility.o prp.o sqrtm1.o euclid_prime_find_root.o
	g++ -o prp prp.o paulunderwood/gw_utility.o $(LDDFLAGS)
	g++ -o sqrtm1 sqrtm1.o paulunderwood/gw_utility.o $(LDDFLAGS)
	g++ -o euclid_prime_find_root euclid_prime_find_root.o paulunderwood/gw_utility.o $(LDDFLAGS)

p95v3019b14:
	unzip -x p95v3019b14.source.zip -d p95v3019b14 > /dev/null
	cd p95v3019b14/gwnum; make -f make64 > /dev/null

paulunderwood/gw_utility.o:
	cd paulunderwood; make gw_utility.o

prp.o: prp.cc 
	g++ -c $< $(CCFLAGS)

sqrtm1.o: sqrtm1.cc 
	g++ -c $< $(CCFLAGS)

euclid_prime_find_root.o: euclid_prime_find_root.cc
	g++ -c $< $(CCFLAGS)


cpplint: prp.cc
	cpplint --filter=-legal/copyright $<

cppcheck: prp.cc
	cppcheck --enable=all --suppress=missingIncludeSystem $< --check-config

cpplinte: euclid_prime_find_root.cc
	cpplint --filter=-legal/copyright $<

cppchecke: euclid_prime_find_root.cc
	cppcheck --enable=all --suppress=missingIncludeSystem $< --check-config

clean:
	rm -f sqrtm1 prp euclid_prime_find_root *.o paulunderwood/gw_utility.o
	rm -rf p95v3019b14
