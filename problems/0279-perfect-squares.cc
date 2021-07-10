class Solution {
public:
    unordered_map<int, int> m;
    int numSquares(int n) {
        if (n == 0) return 0;
        if (m[n] > 0) return m[n];
         
        int s = 1;
        
        int result = n;
        while (s * s <= n) {
            int sub = numSquares(n - s * s);
            result = min(result, sub + 1);
            s++;
        }
        
        m[n] = result;
        return result;
    }
};
