#include <iostream>
#include <vector>
using namespace std;

int odl[1001];
vector<pair<int, int>> graf[1001];

// bford zwroci true jesli nie ma ujemnego cyklu i mamy tez tablice odleglosci s od kazdego innego, false jesli jest

bool bf(int s, int n){
	for (int i=1; i<n; i++){
		for (int v=1; v<=n; v++){
			for (auto x : graf[v]){
				odl[x.first] = min(odl[x.first], odl[v]+x.second);
			}
		}
	}
	for (int i=1; i<=n; i++){
		for (auto x : graf[i]) if (odl[x.first]>odl[i]+x.second) return false;
	}
	return true;
}
