#include <vector>
#include <unordered_map>
using namespace std;

//중복검사

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 1. unordered map
        unordered_map<int,int> count;

        for (int x : nums){
            count[x]++;
            if (count[x]>1){
                return true;
            }
        }
        return false;
        // Vaector
        int n = nums.size();
        for (int i =0 ; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i]==nums[j])
                    return true;
            }
        }
        return false;
    }
};