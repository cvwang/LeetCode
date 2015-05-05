#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int countPrimes(int n){
	int counter = 0;
	vector<bool> primeList(n, true);
	int end = sqrt(n);
	for(int i=2; i<n; ++i){
		if(primeList[i]){
			++counter;
			// this is necessary to prevent int overflow,
			// array out-of-bounds. e.g. 1000000^2
			if(i>end) continue;
			// cout << i << '\n';
			for(int j=i*i; j<n; j+=i){
				primeList[j] = false;
			}
		}
	}
	return counter;
}

int main(){
	int num;
	cin >> num;
	cout << "answer: " << countPrimes(num) << '\n';
	// cout << "answer: " << countPrimes(1500000) << '\n';
	return 0;
}