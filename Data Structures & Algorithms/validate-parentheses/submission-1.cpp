class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                temp.push(c);
            }
            else {
                if (temp.empty()) return false;
                switch (c) {
                    case ')': {
                        if (temp.top() != '(') return false;
                        break;
                    }
                    case '}': {
                        if (temp.top() != '{') return false;
                        break;
                    }
                    case ']': {
                        if (temp.top() != '[') return false;
                        break;
                    }
                }
                temp.pop();
            }
        }

        return temp.empty();
        
    }
};
