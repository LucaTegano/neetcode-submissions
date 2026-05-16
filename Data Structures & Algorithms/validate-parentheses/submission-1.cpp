class Solution {
public:
    bool isValid(string s) {
        using namespace std;
        stack<char> st;

        for(char c : s){
            if(c == '(' or c == '[' or c == '{')
                st.push(c);
            else {
        
                if (st.empty()) return false;

                char top = st.top();
                
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop(); // Match found, remove from stack
                } else {
                    return false; // Mismatch found -> Invalid
                }
            }
        }

    // 3. Final check: Stack must be empty for the string to be valid
    return st.empty();
        
    }
};
