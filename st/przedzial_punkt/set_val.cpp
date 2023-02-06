#include <iostream>
using namespace std;

// ustawiamy wartosc na przedziale, pytamy o wartosc w punkcie

const int M = 1<<20;

int t=0; // ilosc zmian 
int st[2*M], last[2*M]; // last[i] - czas ostatniej zmiany w i-tym wierzcholku

void set(int a, int b, int w){
	t++;
	for (a+=M, b+=M; a<b; a/=2, b/=2){
		if (a&1){
			st[a++] = w;
			last[a++] = t;
		}
		if (b&1){
			st[--b] = w;
			last[--b] = w;
		}
	}
}

int val(int i){
	i+=M;
	int res = st[i], l = last[i];
	for (i/=2; i; i/=2){
		if (last[i]<l){
			l = last[i];
			res = st[i];
		}
	}
	return res;
}
