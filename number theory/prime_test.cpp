#include <iostream>
using namespace std;

bool isprime(int n){
	if (n==1 || n==0) return false;
	for (int i=2; i*i<=n; i++){
		if (n%i==0) return false;
	}
	return true;
}
