#include <iostream>
using namespace std;

// wyszukiwanie wystapien wzorca w tekscie

const int P1 = 31, P2 = 37, MOD1 = 1e9+696969, MOD2 = 1e9+2233, MAXN = 1e6+1;

long long pot1[MAXN], pot2[MAXN], hasz1[MAXN], hasz2[MAXN], haszw1, haszw2;

void pre(int n, string s, int k, string w){
	pot1[0] = pot2[0] = 1;
	for (int i=1; i<=n; i++){
		pot1[i] = (pot1[i-1]*P1)%MOD1;
		pot2[i] = (pot2[i-1]*P2)%MOD2;
	}
	for (int i=1; i<=n; i++){
		hasz1[i] = (hasz1[i-1]*P1+s[i-1]-'a'+1)%MOD1;
		hasz2[i] = (hasz2[i-1]*P2+s[i-1]-'a'+1)%MOD2;
	}
	for (int i=1; i<=k; i++){
		haszw1 = (haszw1*P1+w[i-1]-'a'+1)%MOD1;
		haszw2 = (haszw2*P2+w[i-1]-'a'+1)%MOD2;
	}
}

long long normalizuj(long long a, int M){
	return ((a%M)+M)%M;
}

bool te(long long a, long long b, int M){
	return normalizuj(a, M)==normalizuj(b, M);
}

void rk(int n, string s, int k, string w){
	pre(n, s, k, w);
	for (int i=1; i<=n-k+1; i++){
		long long hasz = hasz1[i+k-1]-(hasz1[i-1]*pot1[k])%MOD1;
		if (!te(haszw1, hasz, MOD1)) continue;
		hasz = hasz2[i+k-1]-(hasz2[i-1]*pot2[k])%MOD2;
		if (te(haszw2, hasz, MOD2)) cout << i << '\n';
	}
}

int main(){
	int n, k; string s, w;
	cin >> n >> s >> k >> w;
	rk(n, s, k, w);
}
