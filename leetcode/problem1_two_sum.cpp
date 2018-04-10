/*

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for (i = 0; i < nums.size(); ++i) {
            int left = target - nums[i];
            for (j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == left)
                    return vector<int>{i,j};
            }
        }
        return vector<int>{};
    }
};
