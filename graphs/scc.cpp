#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+1;

vector <int> in[MAXN], out[MAXN], scc[MAXN], order;
bool odw[MAXN];

void dfs1(int v){
	odw[v] = true;
	for (auto x : out[v]){
		if (!odw[x]) dfs1(x);
	}
	order.push_back(v);
}

void dfs2(int v, int i){
	odw[v] = true;
	scc[i].push_back(v);
	for (auto x : in[v]){
		if (!odw[x]) dfs2(x, i);
	}
}

void build(int n){
	for (int i=1; i<=n; i++) if (!odw[i]) dfs1(i);
	reverse(order.begin(), order.end());
	for (int i=1; i<=n; i++) odw[i] = false;
	
	int cnt=0;
	for (auto x : order){
		if (!odw[x]){
			cnt++;
			dfs2(x, cnt);
		}
	}
}
