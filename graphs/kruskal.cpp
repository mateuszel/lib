#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+1;

vector <pair<int, int>> mst[MAXN];
int ile[MAXN], rep[MAXN];

int fnd(int x){
	if (rep[x]!=x) rep[x] = fnd(rep[x]);
	return x;
}

void join(int x, int y){
	x = fnd(x), y = fnd(y);
	if (ile[x]>ile[y]) swap(x, y);
	ile[y] += ile[x];
	rep[x] = y;
}

void build(int n, vector<pair<int, pair<int, int>>>& edges){
	sort(edges.begin(), edges.end());
	int cnt = 0;
	for (auto [w, edge] : edges){
		if (cnt==n-1) return;
		auto [u, v] = edge;
		if (fnd(u)!=fnd(v)){
			cnt++;
			join(u, v);
			mst[u].push_back({w, v});
			mst[v].push_back({w, u});
		}
	}
}
