#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void add(int i){} // dodajemy i-ty element do ciagu
void remove(int i){} // usuwamy i-ty element z ciagu

// zapytanie suma na przedziale <a, b>
// wejscie indeksujemy od 0

const int BLOCK = 500; // sqrt(n)+-50
int n, m;

struct query{
	int l, r;
};

bool cmp(query a, query b){
	if (a.l/BLOCK!=b.l/BLOCK) return a.l/BLOCK<b.l/BLOCK;
	return (a.l/BLOCK&1) ? (a.r<b.r) : (a.r>b.r); // jesli nr bloku nieparzysty to sortujemy w kolejnosci rosncej, jesli w kolejnosci parzystej to w kolejnosci malejacej
}

vector<int>input;
vector<query>queries;
sort(queries.begin(), queries.end(), cmp);

int cl=0, cr=0, sum=0;
add(cl);
for (auto q : queries){
	int L = q.l, R = q.r; // L,R - przedzial z aktualnego zapytania
	while (cr<R) cr++, add(cr);
	while (cl>L) cl--, add(cl);
	while (cr>R) remove(cr), cr--;
	while (cl<L) remove(cl), cl++;
}
