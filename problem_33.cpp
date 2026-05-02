#include <iostream>
#include <vector>

using namespace std;
// Invariant: rotated list is two portions(left sorted, right sorted)
// the key is to check where the mid is then discuss all cases

int search(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    while(left <= right){ // important to add <= not < only
        int mid =  left + ((right - left) / 2); // distance + offset (like the window)
        if(target == nums[mid]){
            return mid;
        }
        if(target == nums[right]){
            return right;
        }
        if(target == nums[left]){
            return left;
        }
        if(nums[0] <= nums[mid]){ // mid belongs to the left sorted
            if(target < nums[mid]){
                if(target < nums[left]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            else{
                left = mid+1;
            }
        }
        else { // mid belongs to the right sorted
            if(target > nums[mid]){
                if(target > nums[right]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                right = mid-1;
            }
        }

    }
    return -1;

}

int main(){
    // vector<int> test = {2, 3, 4, 5, 6, 7, 8, 9, 1};
    // vector<int> test = {7,8,9,1,2,3,4,5,6};
    // vector<int> test = {7};
    vector<int> test = {4,5,6,7,0,1,2};
    // vector<int> test = {1,2,3,4,5,6,7};
    // vector<int> test = {9,10,11,12,1,2,3,4,5,6,7,8};
   return search(test, 0);
}