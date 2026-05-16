class Solution {
public:
    bool isMatching(char a, char b) {
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
    }

    bool isValid(string s) {
        stack<char> stack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (stack.empty() || !isMatching(stack.top(), c)) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};