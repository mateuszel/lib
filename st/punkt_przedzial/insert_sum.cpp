#include <iostream>
using namespace std;

// ustawiamy wartosc w punkcie, pytamy o sume na przedziale

const int M = 1<<20; // 2^20 ~ 1e6

long long st[2*M];

void insert(int i, int w){ // ustawia i-ty element na w
	i+=M;
	st[i] = w;
	for (i/=2; i; i/=2) st[i] = st[i*2]+st[i*2+1];
}

long long sum(int a, int b){ // zwraca sume elementow z przedzialu <a, b)
	long long res = 0;
	for (a+=M, b+=M; a<b; a/=2, b/=2){
		if (a&1) res += st[a++];
		if (b&1) res += st[--b];
	}
	return res;
}
