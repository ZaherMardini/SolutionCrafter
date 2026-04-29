#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    while(left <= right){ // important to add <= not < only
        int center =  left + ((right - left) / 2); // distance + offset (like the window)
        if(target == nums[center]){
            return center;
        }
        if(target > nums[center]){
            left = ++center;
        }
        else{
            right = --center;
        }
    }
    return -1;
}
int main(){
    vector<int> test = {-1,0,3,5,9,12};
    search(test, 9);
}