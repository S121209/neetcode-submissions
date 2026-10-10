class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap(stones.begin(), stones.end());
        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if (x == y) {
                continue;
            }
            
            int result = (x > y) ? x-y : y-x;

            maxHeap.push(result);
        }

        if (maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};
