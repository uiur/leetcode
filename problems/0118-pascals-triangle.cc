// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
// Memory Usage: 7.6 MB, less than 22.80% of C++ online submissions for Pascal's Triangle.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return vector<vector<int>>{{ 1 }};

        vector<int> current;
        vector<vector<int>> prev = generate(numRows - 1);
        vector<int>& prev_last = prev[prev.size() - 1];

        current.push_back(1);
        for (int i = 0; i < prev_last.size() - 1; i++) {
            current.push_back(prev_last[i] + prev_last[i+1]);
        }
        current.push_back(1);

        prev.push_back(current);
        return prev;
    }
};
