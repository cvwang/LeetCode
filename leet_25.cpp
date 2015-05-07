#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Reverse Nodes in k-Group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	ListNode* root = head;
    	ListNode* lastEnd = nullptr;
    	ListNode* curr = head;
    	int counter = 0;
    	while(curr){
    		// lastEnd = curr;
    		ListNode* keepHead = curr;
    		ListNode* temp = curr;
    		// check if long enough
    		for(int i=0; i<k-1; ++i){
    			temp = temp->next;
    			// if not long enough, fix lastEnd's next and return root
    			if(!temp){
    				if(lastEnd) lastEnd->next = curr;
    				return root;
    			}
    		}
    		temp = curr;
			curr = curr->next;
    		for(int i=0; i<k-1; ++i){
    			ListNode* temp2 = curr->next;
    			curr->next = temp;
    			temp = curr;
    			curr = temp2;
    		}
    		if(lastEnd) lastEnd->next = temp;
    		lastEnd = keepHead;
    		if(!counter) root = temp;
    		++counter;
    	}
    	// multiple of k nodes found. fix lastEnd's next and return root
    	if(lastEnd) lastEnd->next = nullptr;
        return root;
    }
};

int main(){
	// ListNode *root = nullptr;
	ListNode *root = new ListNode(0);
	ListNode *curr = root;
	for(int i=1; i<10; ++i){
		curr->next = new ListNode(i);
		curr = curr->next;
	}
	curr = root;
	while(curr){
		cout << curr->val << '\n';
		curr = curr->next;
	}
	Solution sol;
	curr = sol.reverseKGroup(root, 0);
	cout << "answer:\n";
	while(curr){
		cout << curr->val << '\n';
		curr = curr->next;
	}
	return 0;
}