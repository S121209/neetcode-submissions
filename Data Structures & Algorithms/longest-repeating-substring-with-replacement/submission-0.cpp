class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxLen = 0;
        int largestFreq = 0;
        int largestKey;
        unordered_map<char, int> strs;

        if (s.empty()) return 0;

        for (int r = 0; r < s.size(); r++) {
            strs[s[r]]++;

            if (strs[s[r]] > largestFreq) {
                largestFreq = strs[s[r]];
                largestKey = s[r];
            }

            while (r-l+1 - largestFreq > k) {
                strs[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r - l);
        }
        
        return maxLen+1;
    }
};
