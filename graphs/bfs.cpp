#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2e9+1;
const int MAXN = 1e6+1;

vector <int> graf[MAXN];
long long odl[MAXN];

void bfs(int s){
	queue<int> q;
	q.push(s);
	
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (auto x : graf[v]){
			if (!odl[x]&&x!=s){
				odl[x] = odl[v]+1;
				q.push(x);
			}
		}
	}
}
