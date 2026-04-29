#include <iostream>
#include <vector>

using namespace std;

//shrink window if we reached the target or bigger
//record window size and minSize


int minSubArrayLen(int target, vector<int>& nums) {
    int windowSum = 0;
    int minSize = INT32_MAX;
    int left = 0;
    int windowSize = 0;
    for(int right = 0; right < nums.size(); right++){
        windowSum += nums[right];
        while(target <= windowSum){ 
            windowSize = right - left + 1;
            minSize = min(minSize, windowSize);
            windowSum-= nums[left];
            left++;
        }
    }
    return (minSize == INT32_MAX ? 0 : minSize);
}

int main(){
    vector<int> test = { 2,3,1,2,4,3 };
// # Basic case
// target=7, nums=[2,3,1,2,4,3] → 2  (subarray [4,3])

// # Entire array needed
// target=100, nums=[1,2,3,4,5] → 0

// # Single element satisfies
// target=4, nums=[1,4,4] → 1

// # All elements needed
// target=15, nums=[1,2,3,4,5] → 5

// # Large n, performance test (O(n²) will TLE)
// target=100000, nums=[1]*100000 → 0
    int result = minSubArrayLen(4, test);

}