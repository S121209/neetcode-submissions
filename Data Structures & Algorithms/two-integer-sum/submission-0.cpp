class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        vector<int> result;

        // O(n)
        for (int i = 0; i < nums.size(); i++) {
            numsMap[target - nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            
            auto it = numsMap.find(nums[i]);
            if ((it != numsMap.end()) && (i != it->second)) {
                result.push_back(i);
                result.push_back(it->second);
                break;
            }
        }


        return result;
    }
};
