// Runtime: 8 ms, faster than 54.91% of C++ online submissions for Valid Palindrome.
// Memory Usage: 7.7 MB, less than 23.48% of C++ online submissions for Valid Palindrome.
class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for (int i = 0; i < s.size(); i++) {
            if (('A' <= s[i] && s[i] <= 'Z')) {
                s2 += 'a' + (s[i] - 'A');
            }
            if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) {
                s2 += s[i];
            }
        }
        
        int i = 0;
        int j = s2.size() - 1;
        while (i < j) {
            if (s2[i] != s2[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
};
