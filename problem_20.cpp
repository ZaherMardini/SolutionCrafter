#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    stack<char> buffer;
    unordered_map <char,char>matches = { { '{','}' }, { '[',']' }, { '(',')' } };
    for (char& c : s)
    {
        // openning ? push
        if(matches.count(c)){
            buffer.push(c);
        }
        // closing  ? check top if matches
        else if(!buffer.empty() && matches.at(buffer.top()) == c){
                buffer.pop();
            }
            else{
                return false;
            }
    }
    return buffer.empty();
}


int main(){
    string test = "{((}))}";
    bool result = isValid(test);
}