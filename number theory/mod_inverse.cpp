#include <iostream>
using namespace std;

const int MAXN = 1e6+1;
const int MOD = 1e9+7; // liczba pierwsza
const int ALTMOD = 1e9+33; // inna liczba pierwsza

long long exp(long long a, int e){ // obliczanie a^e % MOD
	e%=MOD;
	long long res = 1;
	while (e){
		if (e&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		e >>= 1; 
	}
	return res%MOD;
}

long long odwr(long long a){
	// odwrotnoscia modulo liczby a mod MOD jest a^MOD-2, bo a^MOD-1 % MOD przystaje do 1, wiec do MOD-2 to bedzie odwwrotnosc
	return exp(a, MOD-2);
}

// sztuczka do odwrotnosci silni w liniowym

long long silnia[MAXN], odw[MAXN];
void pre(int n){
	silnia[0] = 1;
	for (int i=1; i<=n; i++) silnia[i] = (silnia[i-1]*i)%MOD;
	long long inv = odwr(silnia[n]); // to jest odwrotnosc takiej liczby: 1*2*3*4*5*6...*n
	for (int i=n; i>=1; i--){
		// to policzy odwrotnosci modulo kazdej silni
		// bo jak mamy odwrtonosc iloczynu 1...n i pomnozymy razy n to mamy odwrotnosc iloczynu 1...n-1
		odw[i] = inv;
		inv = (inv*i)%MOD;
	}
} 
