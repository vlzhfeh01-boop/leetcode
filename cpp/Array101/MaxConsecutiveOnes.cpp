#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;
        for (int x : nums){
            if (x==1){
                count ++;
                if(count > max_count){
                    max_count = count;
                }
            }
            else{
                count = 0;
            }
        }
        return max_count;
    }
};