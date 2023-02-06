#include <iostream>
using namespace std;

const int MAXN = 1e5+1, LOG = 20;

int arr[MAXN]; // input
int st[MAXN][LOG]; // sparse table
int b2log[MAXN];

int main(){
	int n; cin >> n;
	for (int i=2; i<=n; i++) b2log[i] = b2log[i/2]+1;
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=0; i<n; i++) st[i][0] = arr[i];

	
	for (int e=1; e<LOG; e++){
		for (int i=0; i+(1<<e)-1<n; i++){ //i+e-1 to miejsce na ktorym wyladujemy
			st[i][e] = min(st[i][e-1], st[i+(1<<(e-1))][e-1]);
		}
	}
	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		// przesuniecie indeksow
		//l -= 1, r -= 1;
		int k = b2log[r-l+1];
		cout << min(st[l][k], st[r-(1<<k)+1][k]) << '\n'; // to mozna rozrysowac zawsze to przesuniecie
	}
}
