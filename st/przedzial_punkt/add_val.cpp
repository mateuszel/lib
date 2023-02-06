#include <iostream>
using namespace std;

// dodajemy wartosc na przedziale, pytamy o wartosc w punkcie

const int M = 1<<20;

int st[2*M];

void add(int a, int b, int w){
	for (a+=M, b+=M; a<b; a/=2, b/=2){
		if (a&1) st[a++] += w;
		if (b&1) st[--b] += w;
	}
}

int val(int i){
	i+=M;
	int res = st[i];
	for (i/=2; i; i/=2) res += st[i];
	return res;
}
