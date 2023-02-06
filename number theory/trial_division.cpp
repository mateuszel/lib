#include <iostream>
#include <vector>
using namespace std;

vector <int> factor(int n){
	int N = n; vector <int> res;
	for (int i=2; i*i<=N; i++){
		if (n%i==0){
			res.push_back(i);
			n/=i;
			while (n%i==0){
				res.push_back(i);
				n/=i;
			}
		}
	}
	if (n!=1) res.push_back(n);
	return res;
}
