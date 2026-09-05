class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        vector<int> s1Freq(26);
        vector<int> s2Freq(26);

        if (s1.size() > s2.size()) return false;

        for (char c : s1) {
            s1Freq[c - 'a']++;
        }

        for (int r = 0; r < s2.size(); r++) {
            s2Freq[s2[r] - 'a']++;

            if (r-l + 1 > s1.size()) {
                s2Freq[s2[l] - 'a']--;
                l++;
            }
            
            if (s1Freq == s2Freq) {
                return true;
            }
        }

        return false;
    }
};
