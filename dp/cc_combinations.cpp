#include <iostream>
#include <vector>
using namespace std;

// mamy dane mozliwe nominaly, kazdego z nich mozemy uzywac dowolna liczbe razy - pytanie na ile sposobow mozna ulozyc z nich sume s

int main(){
	int s, n;
	cin >> s >> n;
	vector<int> val(n+1), dp(s+1);
	for (int i=1; i<=n; i++) cin >> val[i];
	dp[0] = 1;
	for (auto x : val){
		for (int i=1; i<=s; i++){
			if (i==x) dp[i]++;
			if (i>x) dp[i] += dp[i-x];
		}
	}
	cout << dp[s] << '\n';
}
