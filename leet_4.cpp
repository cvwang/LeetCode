#include <vector>
#include <iostream>
#include <climits>

#define max(x,y) (x>y) ? x : y
#define min(x,y) (x<y) ? x : y

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int size1 = nums1.size();
	int size2 = nums2.size();
	// keep nums1 size <= nums2 size
	if(size1 > size2) 
		return findMedianSortedArrays(nums2, nums1);
	int totalSize = size1 + size2;
	int begin1 = 0;
	int end1 = size1;
	int mid1 = -1;
	int mid2 = -1;
	while(begin1 <= end1){
		// keep size of right side geq size of left side
		mid1 = (end1 + begin1)/2;
		mid2 = (size1 + size2)/2 - mid1;
		if(mid1 < size1 && mid2 > 0 && nums1[mid1] < nums2[mid2-1]){
			begin1 = mid1+1;
		} 
		// move to left in nums 1
		else if(mid2 < size2 && mid1 > 0 && nums1[mid1-1] > nums2[mid2]){
			end1 = mid1-1;
		} 
		else {
			int num1;
			if(mid1 == size1) {
				num1 = nums2[mid2];
			} else if(mid2 == size2) {
				num1 = nums1[mid1];
			} else {
				num1 = min(nums1[mid1], nums2[mid2]);
			}
			if(totalSize % 2) return num1;
			int num2;
			if(mid1 == 0){
				num2 = nums2[mid2-1];
			} else if(mid2 == 0){
				num2 = nums1[mid1-1];
			} else {
				num2 = max(nums1[mid1-1], nums2[mid2-1]);
			}
			return (num1 + num2)/2.0;
			// break;
		}
	}
}

int main(){
	vector<int> nums1 = {2, 6, 9, 13, 19};
	vector<int> nums2 = {1, 15, 29};
	// vector<int> nums1 = {2, 6, 9, 13, 19, 51};
	// vector<int> nums2 = {1, 15, 29};
	// vector<int> nums1 = {-1, 0, 1, 2, 3};
	// vector<int> nums2 = {5, 6, 7, 8};
	// vector<int> nums1 = {};
	// vector<int> nums2 = {1};
	// vector<int> nums1 = {};
	// vector<int> nums2 = {1, 2};
	// vector<int> nums1 = {1};
	// vector<int> nums2 = {1};
	// vector<int> nums1 = {2, 5};
	// vector<int> nums2 = {1};
	// vector<int> nums1 = {-1, 5};
	// vector<int> nums2 = {1};
	cout << findMedianSortedArrays(nums1, nums2) << '\n';
}