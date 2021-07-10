class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int v = i;
            for (int j = 1; j * j <= i; j++) {
                v = min(v, dp[i - j * j] + 1);
            }
            dp[i] = v;
        }
        
        return dp[n];
    }
};
