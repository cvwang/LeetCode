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
	cout << isomorphic("13","42") << '\n';
	cout << isomorphic("13",",!") << '\n';
	cout << isomorphic("131",",!,") << '\n';
	cout << isomorphic("132",",!,") << '\n';
	return 0;
}

// use unordered_map
bool isomorphic(const string &s, const string &t){
	int size = s.size();
	// if(size != t.size()) return false;
	unordered_map<char, char> charMap;
	vector<bool> charVisited(128, false);
	for(int i=0; i<size; ++i){
		auto it = charMap.find(s[i]);
		// if char not mapped
		if(it == charMap.end()){
			if(charVisited[t[i]] == true) return false;
			charMap[s[i]] = t[i];
			charVisited[t[i]] = true;
		} else {
			if(it->second != t[i]){
				return false;
			}
		}
	}
	return true;
}

