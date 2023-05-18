#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <climits>
#include <cstring>
#include <stack>
using namespace std;

long long binpow(int a, int e){
	long long res=0;
	while (e){
		if (e&1) res *= a;
		a *= a;
		e>>=1;
	}
	return res;
}

vector <int> siv(int n){
	vector<bool> p(n+1);
	p[0] = p[1] = 1;
	for (long long i=2; i<=n; i++){
		if (i*i<=n&&!p[i]) for (long long j=i*i; j<=n; j+=i) p[j] = true;
	}
	return p;
}

int calc_onp(string s){
	stack <int> st;
	for (char x : s){
		if (x==' ') continue;
		if (x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9'||x=='0') st.push(x-'0');
		else if (x=='-'){
			int n1=st.top(); st.pop();
			int n2 = st.top(); st.pop();
			st.push(n1-n2);
		} else if (x=='/'){
			int n1=st.top(); st.pop();
			int n2 = st.top(); st.pop();
			st.push(n1/n2);
		} else if (x=='+'){
			int n1=st.top(); st.pop();
			int n2 = st.top(); st.pop();
			st.push(n1+n2);
		} else{
			int n1=st.top(); st.pop();
			int n2 = st.top(); st.pop();
			st.push(n1*n2);
		}
	}
	return st.top();
}

string decto(int n, int a){
	map<int, char> vals;
	vals.insert({10, 'A'});
	vals.insert({11, 'B'});
	vals.insert({12, 'C'});
	vals.insert({13, 'D'});
	vals.insert({14, 'E'});
	vals.insert({15, 'F'});
	
	string res = "";
	while (n){
		if (n%a>9) res += vals[n%a];
		else res += to_string(n%a);
		n /= a;
	}
	reverse(res.begin(), res.end());
	return res;
}

int todec(string s, int a){
	map<char, int> vals;
	int n = s.size();
	for (int i=0; i<=9; i++) vals.insert({char(i+48), i});
	vals.insert({'A', 10});
	vals.insert({'B', 11});
	vals.insert({'C', 12});
	vals.insert({'D', 13});
	vals.insert({'E', 14});
	vals.insert({'F', 15});
	int pot=1, res=0;
	for (int i=n-1; i>=0; i--){
		res += vals[char(s[i])]*pot;
		pot *= a;
	}
	return res;
}

string cez_crypt(string s, int v){
	v %= 26;
	for (int i=0; i<(int)s.size(); i++){
		char c = s[i];
		if ((int)c+v<=90&&(int)c+v>=65) s[i] = char((int)c+v);
		else if ((int)c+v>90) s[i] = char(64+((int)c+v)%90);
		else if ((int)c+v<65) s[i] = char(91-(65-(int)c-v));
	}
	return s;
}

string cez_dec(string s, int v){
	v %= 26;
	for (int i=0; i<(int)s.size(); i++){
		char c = s[i];
		if ((int)c-v<=90&&(int)c-v>=65) s[i] = char((int)c-v);
		else if ((int)c-v>90) s[i] = char(64+((int)c-v)%90);
		else if ((int)c-v<65) s[i] = char(91-(65-(int)c+v));
	}
	return s;
}

void bub(vector<int>& a){
	int n = a.size();
	for (int i=0; i<n; i++){
		for (int j=1; j<n-i; j++) if (a[j-1]>a[j]) swap(a[j-1],a[j]);
	}
}
