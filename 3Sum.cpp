#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    vector<string> test = {"eat","tea","tan","ate","nat","bat"};
    //{{"bat"},{"nat","tan"},{"ate","eat","tea"}}
    vector<vector<string>> r = groupAnagrams(test);
    cout << "{";
    for (int i = 0; i < r.size(); i++)
    {
        cout << "{";
        for (string word : r[i])
        {
            cout << word << ", ";
        }
        cout << "},";
    }
    cout << "}";
}