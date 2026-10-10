class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int max;
public:
    KthLargest(int k, vector<int>& nums) {
        max = k;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > max) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        if (minHeap.size() > max) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
