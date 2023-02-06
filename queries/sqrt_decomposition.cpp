#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int block = (int)sqrt(n)+1; // rozmiar bloku i ilosc blokow
vector <int> input(n), decomp(block);

int sum(int l, int r){
	// zwraca sume przedzialu <l, r>
	// zakladamy ze 0<=l,r<=n-1
	int res = 0;
	if (l/block==r/block){
		// l i r sa w tym samym bloku
		for (int i=l; i<=r; i++) res += input[i];
	} else{
		for (int i=l/block+1; i<=r/block-1; i++) res += decomp[i];
		for (int i=l; i<=(l+block)/block*block-1; i++) res += input[i];
		for (int i=(r/block)*block; i<=r; i++) res += input[i];
	}
	return res;
}
int main(){

	for (int i=0; i<n; i++) decomp[i/block]+=input[i]; // trzymamy sume danego bloku


}
