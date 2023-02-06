#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6+1;
const int LOG = 21; // log o 1 wiekszy niz log n

pair <int, int> st[2*MAXN][LOG+1];
int base2log[MAXN], depth[MAXN], ft[MAXN];
vector <int> tree[MAXN], rozklad;

void dfs(int v, int d){
	depth[v] = d;
	rozklad.push_back(v);
	ft[v] = (int)rozklad.size()-1;
	for (auto x : tree[v]){
		if (!depth[x]&&x!=1){ // 1 to root
			dfs(x, d+1);
			rozklad.push_back(v);
		}
	}
}

int lca(int a, int b){
	a = ft[a], b = ft[b];
	if (b<a) swap(a, b);
	int lg = base2log[b-a+1]; // najdluzszy skok miesczacy sie na dlugosc
	return min(st[a][lg], st[b-(1<<lg)+1][lg]).second;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=2; i<MAXN; i++) base2log[i] = base2log[i/2]+1;
	int n;
	cin >> n;
	for (int i=1; i<=n-1; i++){
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0);
	for (int i=0; i<(int)rozklad.size(); i++) st[i][0] = {depth[rozklad[i]], rozklad[i]};
	for (int i=1; i<=LOG; i++){
		for (int j=0; j+(1<<i)-1<(int)rozklad.size(); j++){
			st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
		}
	}
}
