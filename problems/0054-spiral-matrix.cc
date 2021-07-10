class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        
        int d = 0;
        vector<int> di {0, 1, 0, -1};
        vector<int> dj {1, 0, -1, 0};
        
        int i = 0;
        int j = 0;
        
        for (int c = 0; c < m * n; c++) {
            result.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            
            int next_i = i + di[d];
            int next_j = j + dj[d];
            if ((!((0 <= next_i && next_i < m) && (0 <= next_j && next_j < n))) || matrix[next_i][next_j] == INT_MIN)  {
                d = (d + 1) % 4;
                next_i = i + di[d];
                next_j = j + dj[d];
            }
            i = next_i;
            j = next_j;
        }
        
        return result;
    }
};
