class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> idx;
        vector<int> result(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            while (!idx.empty() && temperatures[i] > temperatures[idx.top()]) {
                result[idx.top()] = i - idx.top();
                idx.pop();
            }
            idx.push(i);
            

            
        }

        return result;
    }
};
