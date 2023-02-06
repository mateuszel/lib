#include <iostream>
using namespace std;

int odl[101][101]; // zakladamy ze dostalismy macierz w ktorej krawedz miedzy wierzcholkami nie istnieje to odl[x][y] = INF, ww przeciwnym razie jest to odleglosc miedzy nimi, odl[x][x] = 0

void f_w(int n){
	for (int u=1; u<=n; u++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				odl[i][j] = min(odl[i][j], odl[i][u]+odl[u][j]);
			}
		}
	}
}
