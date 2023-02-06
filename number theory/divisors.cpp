#include <iostream>
#include <vector>
using namespace std;

vector <int> div(int n){
	int N = n; vector <int> res;
	for (int i=1; i*i<=N; i++){
		if (n%i==0){
			res.push_back(i);
			res.push_back(n/i);
		}
	}
	return res;
}

