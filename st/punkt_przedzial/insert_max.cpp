#include <iostream>
using namespace std;

// ustawiamy wartosc w punkcie, pytamy o max na przedziale

const int M = 1<<20;
const int INF = 1e9+1;

int st[2*M];

void insert(int i, int w){
	i+=M;
	st[i] = w;
	for (i/=2; i; i/=2) st[i] = max(st[i*2], st[i*2+1]);
}

int maks(int a, int b){
	int res = -INF;
	for (a+=M, b+=M; a<b; a/=2, b/=2){
		if (a&1) res = max(res, st[a++]);
		if (b&1) res = max(res, st[--b]);
	}
	return res;
}
