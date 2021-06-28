// Runtime: 20 ms, faster than 40.95% of C++ online submissions for Word Break.
// Memory Usage: 14.8 MB, less than 19.40% of C++ online submissions for Word Break.
class Solution {
public:
    unordered_map<string, bool> m;
    
    bool dfs(string s, unordered_set<string> &dict_set) {
        if (m.find(s) != m.end()) return m[s];
        if (s.size() == 0) return true;
        
        int size = s.size();
        while (size > 0) {
            if (dict_set.find(s.substr(0, size)) != dict_set.end()) {
                if (dfs(s.substr(size, s.size() - size), dict_set)) {
                    m[s] = true;
                    return true;
                }
            }
            
            size--;
        }
        
        m[s] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict_set;
        for (string word : wordDict) {
            dict_set.insert(word);
        }
        
        return dfs(s, dict_set);
    }
};
