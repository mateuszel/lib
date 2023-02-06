#include <iostream>
#include <vector>
using namespace std;

// szukamy minimalnej ilosci monet w jakiej mozemy wydac s

const int INF = 1e9;

int main(){
	int s, n;
	cin >> s >> n;
	vector <int> val(n+1), dp(s+1, INF);
	dp[0] = 0;
	for (int i=1; i<=n; i++) cin >> val[i];
	for (auto x : val){
		for (int i=1; i<=s; i++){
			if (x==i) dp[i] = 1;
			if (x<i) dp[i] = min(dp[i], dp[i-x]+1);
		}
	}
	cout << dp[s] << '\n';
	// zmiana tego na bool : da sie ulozyc / nie da sie ulozyc
	if (dp[s]>0) cout << "DA SIE\n";
	else cout << "NIE DA SIE\n";
}
