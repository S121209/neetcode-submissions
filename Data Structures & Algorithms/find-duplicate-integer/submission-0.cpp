class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];

        while (1) {
            fast = nums[nums[fast]];
            slow = nums[slow];

            if (slow == fast) {
                slow = nums[0];
                break;
            }
        }
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }

        return fast;
    }
};
