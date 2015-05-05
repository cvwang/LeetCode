#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 68: Text Justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // return words;
        vector<string> formatted;
        // string currLine;
        int beginWord = 0;
        int lineLength = -1;
        for(int i=0; i<words.size(); ++i){
        	if(lineLength + words[i].length() + 1 > maxWidth){
        		cout << beginWord << " " << i-1 << '\n';
        		// submit current line
        		string currLine;
        		currLine += words[beginWord];
        		if(i - beginWord - 1 > 0){
	        		int spacePerLine = (maxWidth - lineLength)/(i - beginWord - 1);
	        		int extraSpaces = (maxWidth - lineLength) % (i - beginWord - 1);
	        		for(int j=beginWord+1; j<i; ++j){
	        			for(int k=0; k<spacePerLine+1; ++k){
	        				currLine += " ";
	        			}
	        			if(extraSpaces){
	        				currLine += " ";
	        				--extraSpaces;
	        			}
	        			currLine += words[j];
	        		}
	        	} else {
	        		while(currLine.size() < maxWidth) currLine += " ";
	        	}
        		formatted.push_back(currLine);

        		// preparing for new line
        		lineLength = -1;
        		beginWord = i;
        	}
        	lineLength += words[i].length() + 1;
        }
		string currLine;
		currLine += words[beginWord];
		for(int j=beginWord+1; j<words.size(); ++j){
			currLine += " " + words[j];
		}
		while(currLine.size() < maxWidth) currLine += " ";
        formatted.push_back(currLine);

        return formatted;
    }
};

int main(){
	// vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
	// Solution sol;
	// vector<string> formatted = sol.fullJustify(words, 16);
	// vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
	// Solution sol;
	// vector<string> formatted = sol.fullJustify(words, 14);
	vector<string> words = {"justification."};
	Solution sol;
	vector<string> formatted = sol.fullJustify(words, 14);
	for(auto &x: formatted) cout << x << '\n';
}