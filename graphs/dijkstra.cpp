#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2e9+1;
const int MAXN = 1e6+1;

vector <pair<int, int>> graf[MAXN];
long long odl[MAXN];

void dijkstra(int s, int n){
	for (int i=1; i<=n; i++) if (i!=s) odl[i] = INF;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (auto x : graf[s]) pq.push({-x.second, {s, x.first}});
	
	while (!pq.empty()){
		auto k = pq.top(); pq.pop();
		if (odl[k.second.second]>odl[k.second.first]-k.first){
			odl[k.second.second] = odl[k.second.first]-k.first;
			for (auto x : graf[k.second.second]){
				pq.push({-x.second, {k.second.second, x.first}});
			}
		}
	}
}
