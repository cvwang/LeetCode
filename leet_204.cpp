#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// int countPrimes(int n){
// 	int counter = 0;
// 	vector<int> primeList;
// 	if(n >= 2){
// 		primeList.push_back(2);
// 		++counter;
// 	}
// 	for(int j=3; j<=n; j+=2){
// 		int end = sqrt(j);
// 		bool prime = true;
// 		// for(int i=2; i<=end; ++i){
// 		// 	if((j/i) * i == j){
// 		// 		// ++counter;
// 		// 		prime = false;
// 		// 		break;
// 		// 	}
// 		// }
// 		for(int i=0; i<primeList.size(); ++i){
// 			if(end < primeList[i]) break;
// 			if((j/primeList[i]) * primeList[i] == j){
// 				prime = false;
// 				break;
// 			}
// 		}
// 		if(prime){
// 			++counter;
// 			primeList.push_back(j);
// 			// cout << j << '\n';
// 		}
// 	}
// 	return counter;
// }

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
	// for(int i = 2; i<1; ++i) cout << "hi\n";
	return counter;
}

int main(){
	int num;
	cin >> num;
	cout << "answer: " << countPrimes(num) << '\n';
	// cout << "answer: " << countPrimes(1500000) << '\n';
	return 0;
}