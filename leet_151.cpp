#include <iostream>
#include <cstring>

using namespace std;

void breakCipher(string &s) {
	int length = s.size();

	int rememberSpot = 0;
	int tempSpot = 0;

	// delete extra spaces
	// begin trail
	for(int i=0; i<length; ++i){
		// if(s[i] == ' ') continue;
		if(s[i] != ' '){
			s.erase(0,i);
			length -= i;
			break;
		}
		if(i == length-1){
			s.erase(0,length);
			length -= length;
			break;
		}
	}
	// end trail
	for(int i=1; i<=length; ++i){
		if(s[length-i] != ' '){
			s.erase(length-i+1,i-1);
			length -= i-1;
			break;
		}
	}

	// reverse the string 
	for(int i=0; i<length/2; ++i){
		char temp = s[i];
		s[i] = s[length-1-i];
		s[length-1-i] = temp;
	}

	// reverse the individual words
	rememberSpot = 0;
	for(int i=0; i<length; i++){
		if(s[i] == ' '){
			tempSpot = i - 1;
			while(rememberSpot < tempSpot){
				int temp = s[rememberSpot];
				s[rememberSpot++] = s[tempSpot];
				s[tempSpot--] = temp;
			}
			// delete extra spaces
			for(int j=i+1; j<length; ++j){
				if(s[j] != ' '){
					if(j-i > 1){
						s.erase(i,j-i-1);
						length -= j-i-1;
					}
					break;
				}
			}
			rememberSpot = i + 1;
		}
	} 
	tempSpot = length-1;
	while(rememberSpot < tempSpot){
		char temp = s[rememberSpot];
		s[rememberSpot++] = s[tempSpot];
		s[tempSpot--] = temp;
	}
}

int main(int argc, char **argv) {
	// string test = "hey it's me charles.";
	// string test = "    hey it's me charles.  ";
	string test = "    hey it's     me charles.  ";
	// string test = " ";
	// char str[256] = " abc def ghi";
	// char str[256] = "ghi def abc ";
	cout << test << "\n";
	cout << test.size() << "\n";
	breakCipher(test);
	cout << test << "\n";
	cout << test.size() << "\n";
}