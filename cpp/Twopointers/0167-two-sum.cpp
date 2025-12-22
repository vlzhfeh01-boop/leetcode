#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result ;
        int cnt = numbers.size();
        int left, right;
        for(left=0,right=cnt-1;left<right;){
            int twosum = numbers[left] + numbers[right];
            if(twosum == target){
                result = {left+1,right+1};
                return result;
            }
            else if(twosum < target)
                left++;
            else 
                right--;
        }
        return result;
    }
};

int main(){
    class Solution sol1;

    vector<int> numbers = {2,7,11,15};
    int target = 9;

    vector<int> res = sol1.twoSum(numbers,target);

    cout << "Result index : ";
    for(auto g : res){
        cout << g << " ";
    }
    cout << endl;

    return 0;
}