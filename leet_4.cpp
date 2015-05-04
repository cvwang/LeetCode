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
	// int begin2 = 0;
	int end1 = size1;
	int mid1 = -1;
	int mid2 = -1;
	while(begin1 <= end1){
		// keep size of right side geq size of left side
		mid1 = (end1 + begin1)/2;
		mid2 = (size1 + size2)/2 - mid1;
		cout << "begin1: " << begin1 << " mid1: " << mid1 << " end1: " << end1 << '\n';
		cout << "mid2: " << mid2 << '\n';
		// if(mid1 == 0 || mid1 == 0)
		// move to right in nums1
		if(mid1 == 0){
			if(totalSize % 2){
				if(size1)
					return min(nums1[mid1], nums2[mid2]);
				else
					return nums2[mid2];
			}
			else{
				if(size1)
					if(size2 > 1)
						return ((min(nums1[mid1],nums2[mid2])) + nums2[mid2-1]) / 2.0;
					else
						return (nums1[mid1] + nums2[mid2-1]) / 2.0;
				else
					return (nums2[mid2] + nums2[mid2-1]) / 2.0;
			}
		}
		else if(mid1 == size1){
			if(totalSize % 2) return nums2[mid2];
			else{
				if(mid2 == 0){
					return (nums1[mid1-1]+nums2[mid2])/2.0;
				} else{
					return (nums2[mid2]+nums2[mid2-1])/2.0;
				}
			}
		}
		else if(nums1[mid1] < nums2[mid2-1]){
			if((nums2[mid2-1] <= nums1[mid1]) && (nums1[mid1-1] <= nums2[mid2])){
				cout << "here1\n";
				break;
			}
			begin1 = mid1+1;
		} 
		// move to left in nums 1
		else if(nums1[mid1-1] > nums2[mid2]){
			if((nums2[mid2-1] <= nums1[mid1]) && (nums1[mid1-1] <= nums2[mid2])){
				cout << "here2\n";
				break;
			}
			end1 = mid1-1;
		} 
		else {
			cout << "here3\n";
			break;
		}
	}
	// end
	cout << nums1[mid1] << " " << nums2[mid2] << '\n';
	if(totalSize % 2) return min(nums1[mid1], nums2[mid2]);
	else
		return ((min(nums1[mid1],nums2[mid2])) + (max(nums1[mid1-1],nums2[mid2-1]))) / 2.0;
}

int main(){
	// vector<int> nums1 = {2, 6, 9, 13, 19};
	// vector<int> nums2 = {1, 15, 29};
	// vector<int> nums1 = {2, 6, 9, 13, 19, 51};
	// vector<int> nums2 = {1, 15, 29};
	// vector<int> nums1 = {-1, 0, 1, 2, 3};
	// vector<int> nums2 = {5, 6, 7, 8};
	// vector<int> nums1 = {1};
	// vector<int> nums2 = {1};
	vector<int> nums1 = {2, 5};
	vector<int> nums2 = {1};
	cout << findMedianSortedArrays(nums1, nums2) << '\n';
}