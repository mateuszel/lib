#include <iostream>
using namespace std;

const int MAXN = 1e5+1, LOG = 20;
int b2log[MAXN], arr[MAXN], st[MAXN][LOG];

int main(){
	int n; cin >> n;
	for (int i=2; i<=n; i++) b2log[i] = b2log[i/2]+1;
	for (int i=0; i<n; i++){
		cin >> arr[i];
		st[i][0] = arr[i];
	}
	for (int e=1; e<LOG; e++){
		for (int i=0; i+(1<<e)-1<n; i++){
			st[i][e] = max(st[i][e-1], st[i+(1<<e)][e-1]);
		}
	}
	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		int k = b2log[r-l+1];
		cout << max(st[l][k], st[r-(1<<k)+1][k]) << '\n';
	}
}
