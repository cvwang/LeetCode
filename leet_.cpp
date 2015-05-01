#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int countPrimes(int n){
	int counter = 0;
	for(int j=2; j<=n; ++j){
		int end = sqrt(j);
		bool prime = true;
		for(int i=2; i<=end; ++i){
			if((j/i) * i == j){
				// ++counter;
				prime = false;
				break;
			}
		}
		if(prime){
			++counter;
			// cout << j << '\n';
		}
	}
	return counter;
}

int main(){
	cout << "answer: " << countPrimes(100) << '\n';
	return 0;
}