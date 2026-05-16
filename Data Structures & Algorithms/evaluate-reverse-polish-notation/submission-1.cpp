class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> stack;
        for (const auto token : tokens) {
            if (token == "+" || token == "-"|| token == "*"|| token == "/") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();

                if (token == "+") {
                    stack.push(a + b);
                } else if (token == "-") {
                    stack.push(a - b);
                } else if (token == "*") {
                    stack.push(a * b);
                } else {
                    stack.push(a / b);
                }
            } else {
                stack.push(stoi(token));
            }
        }
        
        return stack.top();
            }
        };
