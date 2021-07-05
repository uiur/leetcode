class Solution {
public:
    unordered_map<int, vector<int>> m;
    unordered_map<int, bool> checked;
    bool check(unordered_set<int> &s, int i) {
        if (checked.find(i) != checked.end()) return checked[i];
        if (m.find(i) == m.end()) return true;
        if (s.find(i) != s.end()) return false;
        
        s.insert(i);
        for (int p : m[i]) {
            checked[p] = check(s, p);
            if (!checked[p]) return false; 
        }
        s.erase(i);
        
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            if (m.find(a) == m.end()) m[a] = vector<int>();
            m[a].push_back(b);
        }
        
        for (int i = 0; i < numCourses; i++) {
            unordered_set<int> s;
            checked[i] = check(s, i);
            if (!checked[i]) return false;
        }
        return true;
    }
};
