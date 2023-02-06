#include <iostream>

const int MAXN = 1e6+1;

bool zlozona[MAXN];

void sieve(){
	zlozona[0] = zlozona[1] = true; // to nie sa liczby pierwsze
	for (int i=2; i<MAXN; i++){
		if ((long long)i*i<MAXN&&!zlozona[i]) for (long long j=i*i; j<MAXN; j+=i) zlozona[j] = true;
	}
}
