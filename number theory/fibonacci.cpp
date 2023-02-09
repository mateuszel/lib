#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> multi(vector<vector<long long>>& a, vector<vector<long long>>& b){
	vector<vector<long long>> res(2, vector<long long>(2, 0));
	res[0][0] = a[0][0]*b[0][0]+a[0][1]*b[1][0];
	res[0][1] = a[0][0]*b[0][1]+a[0][1]*b[1][1];
	res[1][0] = a[1][0]*b[0][0]+a[1][1]*b[1][0];
	res[1][1] = a[1][0]*b[0][1]+a[1][1]*b[1][1]; 
	return res;
}

long long exp(vector<vector<long long>> a, int e){
	vector<vector<long long>> res(2, vector<long long>(2, 0));
	res[0][0] = 1, res[0][1] = 0, res[1][0] = 1, res[1][1] = 1;
	while (e){
		if (e&1) res = multi(res, a);
		a = multi(a, a);
		e >>= 1;
	}
	return res[1][1];
}
