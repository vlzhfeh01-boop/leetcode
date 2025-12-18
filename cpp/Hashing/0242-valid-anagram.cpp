#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered map solution
        unordered_map<char,int> count1;
        unordered_map<char,int> count2;

        for (char c : s){
            count1[c]++;
        }
        for (char c : t){
            count2[c] ++ ;
        }
        if(count1 == count2){
            return true;
        }
        return false;
        
        // String sloution
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            return true;
        }
        return false;
    }
};

int main(){

    string s1 = "anagram";
    sort(s1.begin(),s1.end());
    cout << s1 << endl;

    return 0;
}