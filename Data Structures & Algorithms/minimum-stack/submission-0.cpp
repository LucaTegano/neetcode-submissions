class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            // If the stack is empty, the new value is both the element and the new minimum.
            s.push({val, val});
        } else {
            // Otherwise, the new minimum is the smaller of the new value and the current minimum.
            int current_min = s.top().second;
            s.push({val, min(val, current_min)});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
    private:
    // The stack stores pairs: {value, current_minimum}
    stack<pair<int, int>> s;
};
