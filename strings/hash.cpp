#include <iostream>
using namespace std;

// podwojne hashowanie
// params:
const int P1 = 31, P2 = 37, MOD1 = 1e9+696969, MOD2 = 1e9+2233, MAXN = 1e6+1;

long long pot1[MAXN], pot2[MAXN];
long long hasz1[MAXN], hasz2[MAXN];

void pre(int n, string s){
	pot1[0] = pot2[0] = 1;
	for (int i=1; i<=n; i++){
		pot1[i] = (pot1[i-1]*P1)%MOD1;
		pot2[i] = (pot2[i-1]*P2)%MOD2;
	}
	for (int i=1; i<=n; i++){
		hasz1[i] = (hasz1[i-1]*P1+s[i-1]-'a'+1)%MOD1;
		hasz2[i] = (hasz2[i-1]*P2+s[i-1]-'a'+1)%MOD2;
	}
}

long long normalizuj(long long a, int M){ // zeby nie zdarzyly sie ujemne wartosci ktore przystaja modulo ale sa rozne
	return ((a%M)+M)%M;
}
