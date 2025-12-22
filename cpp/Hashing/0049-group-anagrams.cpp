#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
// 그룹조건이 뭐지? 를 떠올리고, 같은 조건을 만족시키는 표준형이 있나? 이걸 묶을 수 있나까지 생각.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> cmp;
        for (const string& x : strs){
            string w = x;
            sort(w.begin(),w.end());
            cmp[w].push_back(x);
        }
        vector<vector<string>> result;
        for (auto& x : cmp){
            result.push_back(x.second);
        }

        return result;
        
    }
};

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    class Solution sol1;
    auto res = sol1.groupAnagrams(strs);

    for(auto& g : res){
        cout << "[ ";
        for(auto &w : g) cout << w << " ";
        cout << " ]" << endl;
    }

    return 0;
}