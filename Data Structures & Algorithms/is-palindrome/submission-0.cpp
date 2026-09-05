class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(s.begin(), s.end(),
            [](unsigned char c) {
                return !std::isalnum(c);
            }), s.end());
        int p1 = 0;
        int p2 = s.size() - 1;

        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[p1+i]) != tolower(s[p2-i])) return false;
        }
        return true;
    }
};
