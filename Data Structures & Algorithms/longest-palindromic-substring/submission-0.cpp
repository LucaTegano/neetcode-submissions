class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;

        for(int i = 0; i < s.length(); ++i){
            int len1 = expandAround(s, i, i);
            int len2 = expandAround(s, i ,i+1);

            int len = std::max(len1,len2);

            if(len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
private:
    int expandAround(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // La formula (right - 1) - (left + 1) + 1 semplificata
        return right - left - 1;
    }
};
