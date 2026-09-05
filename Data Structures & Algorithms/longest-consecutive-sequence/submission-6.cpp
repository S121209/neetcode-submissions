class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        set<int> s;

        for (int n : nums) {
            s.insert(n);
        }
        int c = 0;

        vector<int> n;
        for (int nn : s) {
            n.push_back(nn);
        }

        int temp = 0;
        for (int i = 0; i < n.size()-1; i++) {
            if (n[i] + 1 == n[i+1]) c++;
            else {
                temp = (temp > c) ? temp : c;
                c = 0;
                }
        }
        temp = (temp > c) ? temp : c;
        temp++;

        return temp;
    }
};
