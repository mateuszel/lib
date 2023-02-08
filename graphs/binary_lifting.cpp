#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6+1, LOG = 21;

vector <int> graf[MAXN];
int przodkowie[MAXN][LOG], depth[MAXN];

void dfs(int v=1, int p=0){
	depth[v] = depth[p]+1;
	przodkowie[v][0] = p;
	for (auto x : graf[v]){
		if (!depth[x]) dfs(x, v);
	}
}

void pre(int n){
	dfs();
	for (int k=1; k<LOG; k++){
		for (int i=1; i<=n; i++){
			przodkowie[i][k] = przodkowie[przodkowie[i][k-1]][k-1];
		}
	}
}

int lca(int a, int b){
	if (depth[a]<depth[b]) swap(a, b);
	for (int k=LOG-1; k>=0; k--){
		if (depth[przodkowie[a][k]]>=depth[b]) a = przodkowie[a][k];
	}
	if (a==b) return a;
	for (int k=LOG-1; k>=0; k--){
		if (przodkowie[a][k]!=przodkowie[b][k]){
			a = przodkowie[a][k];
			b = przodkowie[b][k];
		}
	}
	return przodkowie[a][0];
}
