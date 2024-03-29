#include <iostream>
#include <vector>
using namespace std;

// szukamy dlugosci lcs

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int n1 = s1.size(), n2 = s2.size();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	
	for (int i=1; i<=n1; i++){
		for (int j=1; j<=n2; j++){
			if (s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	
	cout << dp[n1][n2] << '\n';
	// mozemy odtworzyc lcs idac od n1, n2
	// jesli s1[i]==s2[j] i--, j-- i dodajemy s1[i] do ciagu
	// w przeciwnym razie idziemy do maxa w dpku(w gore lub w lewo)
}
