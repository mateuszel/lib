#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+1;

vector <int> graf[MAXN], topo;
bool odw[MAXN];

void dfs(int v){
	odw[v] = true;
	for (auto x : graf[v]){
		if (!odw[x]) dfs(x);
	}
	topo.push_back(v);
}

void build(int n){
	for (int i=1; i<=n; i++){
		if (!odw[i]) dfs(i);
	}
	reverse(topo.begin(), topo.end());
}
