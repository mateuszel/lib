#include <iostream>
using namespace std;

// dodajemy na przedziale, pytamy o sume na przedziale

const int M = 1<<20;

int st[2*M];
int up[2*M]; // updaty

void lazy(int e, int dl){
	// spychamy wartosc updatu do synow wierzcholka e
	if (up[e]!=0){
		up[2*e] += up[e];
		st[2*e] += up[e]*dl;
		up[2*e+1] += up[e];
		st[2*e+1] += up[e]*dl;
		up[e] = 0;
	}
}

void add(int a, int b, int val, int e=1, int lo=0, int hi=M){
	// <a, b) przedzial z zapytania, val wartosc dodawna 
	if (b<=a) return; // pusty przedzial
	if (a==lo && b==hi){
		// przedzial bazowy
		e[up] += val;
		e[st] += val*(hi-lo);
		return;
	}
	// jezeli przedzial niebazowy to spychamy wartosc update
	lazy(e, (hi-lo)/2);
	int mid = (lo+hi)/2;
	add(a, min(mid, b), val, e*2, lo, mid); // zapytanie <a, b) - więc jak idziemy w lewo to nie chcemy rozpatrywac zbyt dlugiego przedziału
	add(max(mid, a), b, val, e*2+1, mid ,hi); // idziemy w prawo od mid, bo w lewo poszlismy w poprzedniej linijce
	st[e] = st[e*2] + st[e*2+1]; // ta linijka bedzie sie roznila w roznych drzewach, np max(l, p)
}

int query(int a, int b, int e=1, int lo=0, int hi=M){
	if (b<=a) return 0; // wartosc neutralna dla danej operacji, nie zawsze 0
	if (a==lo && b==hi) return st[e]; // przedzial bazowy
	
	lazy(e, (hi-lo)/2);
	int mid = (lo+hi)/2;
	int q1 = query(a, min(b, mid), e*2, lo, mid), q2 = query(max(a, mid), b, e*2+1, mid, hi);
	return q1+q2; // ta linijka decyduje o operajci jaka robimy
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
			add(b, c+1, d);
		}
	}
}
