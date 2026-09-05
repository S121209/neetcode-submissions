class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> h_idx;
        int largest = 0;
        int l, r, area;
        
        for (int i = 0; i < heights.size(); i++) { 
            if (h_idx.empty()) {
                h_idx.push(i);
                continue;
            }

            if (heights[h_idx.top()] > heights[i]) {
                r = i;
                
                while (!h_idx.empty() && heights[h_idx.top()] > heights[i]) {
                    int t = h_idx.top();
                    h_idx.pop();
                    if (h_idx.empty()) l = -1;
                    else l = h_idx.top();
                    area = heights[t] * (r - l - 1);
                    largest = (area > largest) ? area : largest;
                }
            }
            h_idx.push(i);
        }

        if (!h_idx.empty()) {
            int r, l, area;
            r = heights.size();
            while (!h_idx.empty()) {
                int t = h_idx.top();
                h_idx.pop();
                if (h_idx.empty()) l = -1;
                else l = h_idx.top();
                area = heights[t] * (r - l - 1);
                largest = (area > largest) ? area : largest;
            }
        }

        return largest;
    }
};
