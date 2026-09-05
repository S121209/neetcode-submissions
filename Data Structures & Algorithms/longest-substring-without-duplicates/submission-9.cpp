class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> strs;
        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            while (strs.contains(s[r])) {
                strs.erase(s[l]);
                l++;
            }

            strs.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
