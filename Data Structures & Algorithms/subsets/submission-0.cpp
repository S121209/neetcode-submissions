class Solution {
    void dfs(int index, const std::vector<int>& nums, std::vector<int>& current, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        dfs(index + 1, nums, current, result);
        current.pop_back();
        dfs(index + 1, nums, current, result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        dfs(0, nums, current, result);
        return result;
        
    }
};
