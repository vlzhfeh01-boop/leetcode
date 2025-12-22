#include<vector>
#include<algorithm>
using namespace std;

/*
인덱스가 달라져도 값이 같으면 안된다.
중복제거를 위해서 left,right index모두를 더하고 빼주면서 같은 값이 재사용 되지 않도록 해준다.
어차피 i로 인한 인덱스가 고정되어있다면, 고정된 다른 값에 의해서 다른 값은 자동으로 결정된다.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long total = (long long)nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                    // 정답을 찾은 지점의 (j,k)는 이미 소모했으니, 둘 다 다음 후보로 넘어가는게 자연스럽다.
                    // 만약 이전과 같은 값이 나오면, 달라질때까지 넘어간다.
                }
            }
        }
        return res;
    }
};
