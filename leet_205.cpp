#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isomorphic(const string &a, const string &b);

int main(){
	string a = "paper";
	string b = "title";
	cout << isomorphic(a,b) << '\n';
	a = "foo";
	b = "bar";
	cout << isomorphic(a,b) << '\n';
	a = "egg";
	b = "add";
	cout << isomorphic(a,b) << '\n';
	a = "paper";
	b = "tetle";
	cout << isomorphic(a,b) << '\n';
	return 0;
}

// use unordered_map
bool isomorphic(const string &a, const string &b){
	int size = a.size();
	// if(size != b.size()) return false;
	unordered_map<char, char> charMap;
	vector<bool> charVisited(26, false);
	for(int i=0; i<size; ++i){
		auto it = charMap.find(a[i]);
		// if char not mapped
		if(it == charMap.end()){
			if(charVisited[b[i]-97] == true) return false;
			charMap[a[i]] = b[i];
			charVisited[b[i]-97] = true;
		} else {
			if(it->second != b[i]){
				return false;
			}
		}
	}
	return true;
}

