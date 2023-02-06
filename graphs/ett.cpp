#include <iostream>
#include <vector>
using namespace std;

// rozkladamy drzewo na tablice przy uzyciu czasow pre i post

const int MAXN = 1e5+1;

vector <int> tree[MAXN];
int flat[2*MAXN+1], t=0;
bool odw[MAXN];

void dfs(int v){
	t++;
	flat[t] = v;
	for (auto x : tree[v]) if (!odw[x]) dfs(x);
	t++;
}
