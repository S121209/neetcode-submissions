class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int target = -nums[i];
            int j = i+1;
            int k = nums.size() -1;

            while(j < k) {
                if (j != i+1 && nums[j] == nums[j-1]) {
                    j++;
                    continue;
                }
                if (k != nums.size() - 1 && nums[k] == nums[k+1]) {
                    k--;
                    continue;
                }
                if (nums[j] + nums[k] > target) {
                    k--;
                }
                else if (nums[j] + nums[k] < target) {
                    j++;
                }
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                }
            }
        }

        return result;
    }
};
