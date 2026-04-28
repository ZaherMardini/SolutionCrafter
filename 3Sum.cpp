#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>>results;
		const int fixedEnd = nums.size() - 1;

		for(int first = 0; first < nums.size() - 2; first++)
		{
			// reset the window at every loop
			int left = first+1;
			int right = fixedEnd;
			if(first > 0 && nums[first -1] == nums[first]){ continue; }
			// fix first then run twoSum until there is no triplets

			// two sum
			int sum;
			while(left < right)
			{
				sum = nums[first] + nums[left] + nums[right];
				if(sum == 0){
					// record triplet
					results.push_back({nums[first], nums[left], nums[right]});
					// skip duplicate Left values
					while(left < right && nums[left +1] == nums[left]){ left++; }
					// skip duplicate Right values
					while(left < right && nums[right -1] == nums[right]){ right--; }
					// then move both pointers inward	
					left++;
					right--;
				}
				else if(sum < 0){
					left++;
				}
				else if(sum > 0){
					right--;
				}
			}
		}
		return results;
	}


int main(){
		// vector<int> test = {-1, -1, -1, 0, 1};
		// vector<int> test = {-4, -1, -1, 0, 0, 1, 2};
		vector<int> test = {-2, 0, 0, 2, 2};
		// vector<int> test = {-1, 0, 1};
		// vector<int> test = {-2, -1, 0, 1, 2, 3};

		vector<vector<int>>results;
		results = threeSum(test);
}