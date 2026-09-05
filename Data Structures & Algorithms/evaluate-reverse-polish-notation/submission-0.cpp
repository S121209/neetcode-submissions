class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> pmmd = {"+", "-", "*", "/"};
        stack<string> calc;
        for (string t : tokens) {
            calc.push(t);
            if (ranges::contains(pmmd, t)) {
                calc.pop();
                int rv = stoi(calc.top());
                calc.pop();
                int lv = stoi(calc.top());
                calc.pop();
                int temp;
                if (t == "+") temp = lv + rv;
                else if (t == "-") temp = lv - rv;
                else if (t == "*") temp = lv * rv;
                else if (t == "/") temp = lv / rv;
                else cout << "nope";
                calc.push(to_string(temp));
            }
        }
        return stoi(calc.top());
    }
};
