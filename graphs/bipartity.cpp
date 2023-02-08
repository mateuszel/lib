#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6+1;

vector <int> graf[MAXN];
int clr[MAXN];

void dfs(int v, int p){
	if (clr[p]==1) clr[v] = 2;
	else clr[v] = 1;
	for (auto x : graf[v]){
		if (!clr[x]) dfs(x, v);
	}
}

bool bipartite(int n){
	for (int i=1; i<=n; i++){
		for (auto x : graf[i]){
			if (clr[i]==clr[x]) return false;
		}
	}
	return true;
}
