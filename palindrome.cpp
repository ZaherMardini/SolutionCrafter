#include<iostream>

using namespace std;

string s = "A man, a plan, a canal: Panama";

void getCleanInput(string &s) {
    string result = "";
    for (char c : s) {
        // Check ASCII ranges for 0-9, A-Z, and a-z
        if ((c >= '0' && c <= '9') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z')) {
            c = tolower(c);
            result += c; // Only add if it's alphanumeric
        }
        // All other characters (spaces, punctuation, etc.) are ignored
    }
    s = result;
}

bool isPalindrome(string s){
    if(s == " ") return true;
    getCleanInput(s);
    int right = s.length() - 1;
    int left = 0;
    while(left <= right)
    {
        if(s[left] != s[right]){
            return false;
        }
        right--;
        left++;
    }
    
    return true;
}

int main(){
    // cout << getCleanInput(s) << endl;
    cout << isPalindrome(s) << endl;
    return 0;
}