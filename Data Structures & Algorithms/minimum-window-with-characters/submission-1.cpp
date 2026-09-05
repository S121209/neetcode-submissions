class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int minL;
        int minLen = INT_MAX;
        int matches = 0;
        unordered_map<char, int> sFreq;
        unordered_map<char, int> tFreq;

        if (s.size() < t.size()) return "";

        for (char c : t) {
            tFreq[c]++;
        }
        int required = tFreq.size();

        for (int r; r < s.size(); r++) {
            sFreq[s[r]]++;

            if (sFreq[s[r]] == tFreq[s[r]]) {
                matches++;
            }

            while (matches == required) {
                if (r - l + 1 < minLen) {
                    minL = l;
                    minLen = r - l + 1;
                }
                sFreq[s[l]]--;
                if (tFreq.contains(s[l]) && sFreq[s[l]] < tFreq[s[l]]) {
                    matches--;
                }
                l++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(minL, minLen);
        
    }
};
