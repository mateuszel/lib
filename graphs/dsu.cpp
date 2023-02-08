#include <iostream>
using namespace std;

const int MAXN = 1e6+1;

int ile[MAXN], rep[MAXN];

void pre(int n){
	for (int i=1; i<=n; i++) rep[i] = i;
}

int fnd(int x){
	if (rep[x]!=x) rep[x] = fnd(rep[x]);
	return x;
}

void join(int x, int y){
	x = fnd(x), y = fnd(y);
	if (ile[x]>ile[y]) swap(x, y);
	rep[x] = y;
	ile[y] += ile[x];
}
