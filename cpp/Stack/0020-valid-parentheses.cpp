#include <string>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        // Stack 은 확인하고 싶으면 바로바로 빼는게 좋다.
        stack<char> st1;
        for (char x : s) {
            if(x=='(' || x=='[' || x=='{')
                st1.push(x);
            else {
                if(st1.empty()) return false;

                char top = st1.top();
                st1.pop();
                if((x==')' && top !='(') || (x=='}' && top != '{') || (x==']' && top != '[')) 
                    return false;
            }
        }

        
        return st1.empty();
    }
};

int main(){
    Solution sol1;

    string s = "()[]{}";

    bool valid = sol1.isValid(s);
    cout << boolalpha << valid << endl;
    return 0;
}