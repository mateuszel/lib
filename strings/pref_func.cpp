#include <iostream>
using namespace std;

// wyznaczanie funkcji pref, gdzie pref[i] to dlugosc najdluzszego prefiksu ktory mozna przylozyc w punkcie i

const int P1 = 31, P2 = 37, MOD1 = 1e9+696969, MOD2 = 1e9+2233, MAXN = 1e6+1;

long long pot1[MAXN], pot2[MAXN], hasz1[MAXN], hasz2[MAXN];
int pref[MAXN];

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

long long normalizuj(long long a, int M){
	return ((a%M)+M)%M;
}

bool test(int i, int len){
	long long h_pref = hasz1[len], h_check = hasz1[i+len-1]-(hasz1[i-1]*pot1[len])%MOD1;
	if (normalizuj(h_pref, MOD1)!=normalizuj(h_check, MOD1)) return false;
	h_pref = hasz2[len], h_check = hasz2[i+len-1]-(hasz2[i-1]*pot2[len])%MOD2;
	return normalizuj(h_pref, MOD2)==normalizuj(h_check, MOD2);
}

void build_pref(int n, string s){
	pre(n, s);
	for (int i=1; i<=n; i++){
		int a=0, b=n-i+1, res = 0;
		while (a<=b){
			int mid = (a+b)/2;
			if (test(i, mid)){
				res = max(res, mid);
				a = mid+1;
			} else b = mid-1;
		}
		pref[i] = res;
	}
}
