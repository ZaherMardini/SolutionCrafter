#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Mental model: don't think about comparing, think about what anagrams words got in common?
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> results;
    unordered_map <string, vector<string>> words_map;
    for(string &word : strs){
        string key = word;
        sort(key.begin(), key.end());
        words_map[key].push_back(word);
    }   
    for (auto& [key, value] : words_map){
        results.push_back(value);
    }
    return results;
}

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