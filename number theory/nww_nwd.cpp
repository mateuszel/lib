#include <iostream>
using namespace std;

int nwd(long long a, long long b){
	if (b>a) swap(a, b);
	while (b){
		a%=b;
		swap(a, b);
	}
	return a;
}

long long nww(long long a, long long b){
	return a/nwd(a, b)*b;
}
