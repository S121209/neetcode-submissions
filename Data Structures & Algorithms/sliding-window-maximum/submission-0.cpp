class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        int l = 0;


        // 그니까 r을 계속 늘리면서 r - l + 1 > k 이면 계산하고 l을 늘리기 ㅇㅋ??
        for (int r = 0; r < nums.size(); r++) {
            pq.push({nums[r], r});

            if (r - l + 1 == k) {
                while (pq.top().second < l || pq.top().second > r) {
                    pq.pop();
                }
                result.push_back(pq.top().first);
                l++;
            }
        }

        return result;
    }
};
