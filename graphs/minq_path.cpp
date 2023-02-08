#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6+1, LOG = 21, INF = 2e9;

vector <int> graf[MAXN];
int przodkowie[MAXN][LOG], minq[MAXN][LOG], depth[MAXN], odl[MAXN];

// mamy dana tablice odl[i], gdzie odl[i] to odleglosc danego wierzcholka od jakiegos szczegolnego wierzcholka(zaleznie od zadania)
// dostajac zapytanie a b, chcemy znalezc minimalna wartosc odl[x] na sciezce od a do b

void dfs(int v=1, int p=0){
	przodkowie[v][0] = p;
	depth[v] = depth[p]+1;
	for (auto x : graf[v]){
		if (!depth[x]) dfs(x, v);
	}
}

void pre(int n){	
	for (int k=LOG-1; k>=1; k--){
		for (int i=1; i<=n; i++){
			przodkowie[i][k] = przodkowie[przodkowie[i][k-1]][k-1];
		}
	}
	for (int i=1; i<=n; i++){
		for (int k=0; k<LOG; k++) minq[i][k] = INF;
	}
	for (int i=1; i<=n; i++) minq[i][0] = odl[przodkowie[i][0]];
	for (int k=1; k<LOG; k++){
		for (int i=1; i<=n; i++) minq[i][k] = min(minq[i][k-1], minq[przodkowie[i][k-1]][k-1]);
	}
}

int mini(int a, int b){
	if (depth[b]>depth[a]) swap(a, b);
	int res = min(odl[a], odl[b]);
	for (int k=LOG-1; k>=0; k--){
		if (depth[przodkowie[a][k]]>=depth[b]){
			res = min(res, minq[a][k]);
			a = przodkowie[a][k];
		}
	}
	if (a==b) return res;
	for (int k=LOG-1; k>=0; k--){
		if (przodkowie[a][k]!=przodkowie[b][k]){
			res = min(res, min(minq[a][k], minq[b][k]));
			a = przodkowie[a][k];
			b = przodkowie[b][k];
		}
	}
	return min(res, odl[przodkowie[a][0]]);
}
