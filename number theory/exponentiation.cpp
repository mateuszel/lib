#include <iostream>
using namespace std;

long long exp(int a, int e){
	// a^e
	long long res = 1;
	while (e){
		if (e&1) res *= a;
		a *= a;
		e >>= 1;
	}
	return res;
}
