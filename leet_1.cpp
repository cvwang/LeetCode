#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, vector<int> > valueMap;
    // for(auto &x: nums) cout << x << "\n";
    vector<int> answer;
    for(int i=0; i<nums.size(); ++i) valueMap[nums[i]].push_back(i);
    for(int i=0; i<nums.size(); ++i){
    	auto it = valueMap.find(target - nums[i]);
    	if(it != valueMap.end()){
    		for(auto &x: it->second){
    			if(x != i){
		    		if(i < x){
		    			answer.push_back(i+1);
		    			answer.push_back(x+1);
		    		} else {
		    			answer.push_back(x+1);
		    			answer.push_back(i+1);
		    		}
    				break;
    			}
    		}
    	}
    	if(!answer.empty()) break;
    }
    return answer;
}

int main(){
	vector<int> nums = {2, 7, 11, 15};

	vector<int> answer = twoSum(nums, 17);
	cout << answer[0] << " " << answer[1] << "\n";
	return 0;
}