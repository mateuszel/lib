#include <iostream>
using namespace std;

// ustawiamy wartosc na przedziale, pytamy o sume na przedziale

const int M = 1<<20;

int up[2*M];
long long st[2*M];

void lazy(int e, long long dl){
	if (up[e]!=0){
		up[e*2] = up[e];
		st[e*2] = up[e]*dl;
		up[e*2+1] = up[e];
		st[e*2+1] = up[e]*dl;
		up[e] = 0;
	}
}

void update(int a, int b, int val, int e=1, int lo=0, int hi=M){
	if (b<=a) return;
	if (a==lo && b==hi){
		up[e] = val;
		st[e] = val*(hi-lo);
		return;
	}
	lazy(e, (hi-lo)/2);
	int mid = (lo+hi)/2;
	update(a, min(mid, b), val, e*2, lo, mid);
	update(max(a, mid), b, val, e*2+1, mid, hi);
	st[e] = st[e*2] + st[e*2+1];
}

int query(int a, int b, int e=1, int lo=0, int hi=M){
	if (b<=a) return 0;
	if (a==lo && b==hi) return st[e];
	
	lazy(e, (hi-lo)/2);
	int mid = (lo+hi)/2;
	int q1 = query(a, min(mid, b), e*2, lo, mid), q2 = query(max(a, mid), b, e*2+1, mid, hi);
	return q1+q2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) cin >> st[i+M];
	for (int i=M-1; i>=1; i--) st[i] = st[i*2+1]+st[i*2];
	
	int k; cin >> k;
	while (k--){
		int a, b, c;
		cin >> a >> b >> c;
		if (a==-1) cout << query(b, c+1) << '\n';
		else{
			int d; cin >> d;
			update(b, c+1, d);
		}
	}
}
