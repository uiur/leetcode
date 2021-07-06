class Solution {
public:
    
    unordered_map<int, vector<int>> m;
    
    bool dfs(vector<int>& result, unordered_set<int>& taken, unordered_set<int>& checking, int i) {
        if (taken.find(i) != taken.end()) return true;
        if (checking.find(i) != checking.end()) return false;
        
        checking.insert(i);
        if (m.find(i) != m.end()) {
            for (int p : m[i]) {
                if (!dfs(result, taken, checking, p)) return false;
            }
        }
        checking.erase(i);
        
        taken.insert(i);
        result.push_back(i);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int> pre: prerequisites) {
            int a = pre[0];
            int b = pre[1];
            m[a].push_back(b);
        }
        
        unordered_set<int> taken;
        vector<int> result;
        for (int i = 0; i < numCourses; i++) {
            unordered_set<int> checking;
            if (!dfs(result, taken, checking, i)) return vector<int>();
        }
        
        
        return result;
    }
};
