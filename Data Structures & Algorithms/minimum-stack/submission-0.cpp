class MinStack {
    stack<int> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        stack<int> temp = s;

        int min = temp.top();
        temp.pop();

        while(!temp.empty()) {
            min = (temp.top() < min) ? temp.top() : min;
            temp.pop();
        }

        return min;
    }
};
