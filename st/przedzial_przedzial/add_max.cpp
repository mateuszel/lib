#include <iostream>
using namespace std;

const int M = 1<<20;

int st[2*M], up[2*M];

void lazy(int e){
	if (up[e]!=0){
		up[e*2] += up[e];
		st[e*2] += up[e];
		up[e*2+1] += up[e];
		st[e*2+1] += up[e];
		up[e] = 0;
	}
}

void add(int a, int b, int val, int e=1, int lo=0, int hi=M){
	if (b<=a) return;
	if (a==lo && b==hi){
		st[e] += val;
		up[e] += val;
		return;
	}
	lazy(e);
	int mid = (lo+hi)/2;
	add(a, min(mid, b), val, e*2, lo, mid);
	add(max(a, mid), b, val, e*2+1, mid, hi);
	st[e] = max(st[e*2], st[e*2+1]);
}

int query(int a, int b, int e=1, int lo=0, int hi=M){
	if (b<=a) return -1;
	if (a==lo && b==hi) return st[e];
	
	lazy(e);
	int mid = (lo+hi)/2;
	int q1 = query(a, min(mid, b), e*2, lo, mid), q2 = query(max(a, mid), b, e*2+1, mid, hi);
	return max(q1, q2); 
}

int main(){
	/*ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) cin >> st[i+M];
	for (int i=M-1; i>=1; i--) st[i] = max(st[i*2+1], st[i*2]);
	
	int k; cin >> k;
	while (k--){
		int a, b, c;
		cin >> a >> b >> c;
		if (a==-1) cout << query(b, c+1) << '\n';
		else{
			int d; cin >> d;
			add(b, c+1, d);
		}
	}
}
