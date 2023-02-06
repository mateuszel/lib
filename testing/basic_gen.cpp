#include <iostream>
#include <random>
#include <climits>

// random_shuffle - losowanie tablicy
using namespace std;

int MAX = 100;

int rand(int a, int b){
	return a+rand()%(b-a+1);
}

int main(int argc, char **argv){
	srand(atoi(argv[1]));
	
	cout << rand(1, MAX) << " " << rand(2, MAX) << "\n";
	return 0;
}
