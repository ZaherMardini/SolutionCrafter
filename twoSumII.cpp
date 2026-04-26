#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int first = 0;
    int end = numbers.size() - 1;
    vector<int> results;
    int sum;
    while(first < end)
    {
        sum = numbers[first] + numbers[end];
        if(sum == target){
            results.push_back(first +1);
            results.push_back(end +1);
            return results;
        }
        if(sum < target){
            first++;
        }
        if(sum > target){
            end--;
        }
    }
    return results;
}

int main(){
    vector<int> test = { 7,8,11,15,20 };
    int target = 35;
    test = twoSum(test, target);
    cout << test[0] << "," << test[1] << endl;
}