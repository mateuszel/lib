#include <iostream>
#include <vector>
using namespace std;

// dostajemy s - rozmiar plecaka, n - liczbe elementow, i n par liczb v, w - wartosc i waga 

int main(){
	int s, n;
	cin >> s >> n;
	vector <int> v(n+1), w(n+1);
	vector<vector<int>> dp(n+1, vector<int>(s+1, 0));
	for (int i=1; i<=n; i++) cin >> v[i] >> w[i];
	for (int i=1; i<=n; i++){
		// przechodzimy po kazdym przedmiocie
		for (int j=1; j<=s; j++){
			// przechodzimy po kazdym rozmiarze plecaka
			if (j>=w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
		}
	}
	cout << "MAX WYNIK: " << dp[n][s] << '\n';
	// szukanie przedmiotow ktorych uzylismy
	int j=s;
	for (int i=n; i>=1; i--){
		if (dp[i][j]!=dp[i-1][j]){
			cout << i << '\n';
			j -= w[i];
		}
	}
}
