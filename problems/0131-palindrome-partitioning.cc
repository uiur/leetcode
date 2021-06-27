// Runtime: 868 ms, faster than 5.07% of C++ online submissions for Palindrome Partitioning.
// Memory Usage: 433.1 MB, less than 5.01% of C++ online submissions for Palindrome Partitioning.
class Solution {
public:
    
    vector<vector<string>> allPartitions(string s) {
        vector<vector<string>> result;
        result.push_back(vector<string>{s});
        for (int i = 1; i < s.size(); i++) {
            vector<vector<string>> sub_partitions = allPartitions(s.substr(i));
            for (int j = 0; j < sub_partitions.size(); j++) {
                vector<string> current;
                current.push_back(s.substr(0, i));
                for (int k = 0; k < sub_partitions[j].size(); k++) 
                    current.push_back(sub_partitions[j][k]);
            
                result.push_back(current);
            }
        }
        return result;
    }
    
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> all = allPartitions(s);
        vector<vector<string>> result;
        for (int i = 0; i < all.size(); i++) {
            int ok = true;
            for (int j = 0; j < all[i].size(); j++) {
                if (!isPalindrome(all[i][j])) {
                    ok = false;
                    break;
                }
            }
            if (ok) result.push_back(all[i]);
        }
        return result;
    }
};
