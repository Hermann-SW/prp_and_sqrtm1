# prp_and_sqrtm1
Providing prp and sqrtm1 code based on @paulunderwood's gw_utility.[ch] (which is based on gwnum lib).

Related forum posting:  
[https://www.mersenneforum.org/showthread.php?p=656298#post656298](https://www.mersenneforum.org/showthread.php?p=656298#post656298)

# efficiently find primitive root of prime Euclid number

New euclid\_prime\_find\_root.cc (with ```gw_powm()```), transpiled from seq.gp gist:  
https://gist.github.com/Hermann-SW/b4d422842b22da4d5f2838a211f38e02

With ```gw_powm()``` code is much faster than same code with [mpz_powm()](https://gmplib.org/manual/Integer-Exponentiation) on prime Euclid numbers (with 2,038/4,951/5,862 decimal digits):  
```
hermann@7950x:~/prp_and_sqrtm1$ time ./euclid_prime_find_root 643
3

real	0m24.780s
user	0m24.776s
sys	0m0.002s
hermann@7950x:~/prp_and_sqrtm1$ time ./euclid_prime_find_root 1391
24

real	1m46.134s
user	1m46.468s
sys	0m0.056s
hermann@7950x:~/prp_and_sqrtm1$ time ./euclid_prime_find_root 1613
24

real	2m24.651s
user	2m24.982s
sys	0m0.061s
hermann@7950x:~/prp_and_sqrtm1$ 
```

And that is faster than PARI/GP on prime Euclid numbers (with 2,038/4,951/5,862 decimal digits):  
```
hermann@7950x:~/prp_and_sqrtm1$ time ./euclid_prime_find_root 643
3

real	0m24.755s
user	0m24.753s
sys	0m0.001s
hermann@7950x:~/prp_and_sqrtm1$ time ./euclid_prime_find_root 1391
24

real	8m38.019s
user	8m38.001s
sys	0m0.003s
hermann@7950x:~/prp_and_sqrtm1$ time ./euclid_prime_find_root 1613
24

real	15m19.517s
user	15m19.481s
sys	0m0.000s
hermann@7950x:~/prp_and_sqrtm1$
```

Here are the corresponding slower seq.gp runtimes (and those are much faster than GP ```znprimroot()``` runtimes):  
```
? euclid_prime_find_root(643)
cpu time = 29,777 ms, real time = 29,779 ms.
%2 = 3
? euclid_prime_find_root(1391)
cpu time = 9min, 23,013 ms, real time = 9min, 23,064 ms.
%3 = 24
? euclid_prime_find_root(1613)
cpu time = 17min, 2,256 ms, real time = 17min, 2,331 ms.
%4 = 24
? 
```
