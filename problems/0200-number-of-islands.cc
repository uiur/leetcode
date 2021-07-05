class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (!((0 <= i && i < m) && (0 <= j && j < n))) return;
        if (grid[i][j] != '1') return;
        
        grid[i][j] = 'x';
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'x') continue;
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
