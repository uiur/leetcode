class Solution {
public:
    int countPrimes(int n) {
        int i = 2;
        int count = 0;
        vector<bool> prime(n, true);
        for (int i = 2; i < n; i++) {
            if (!prime[i]) continue;
            count++;
            
            for (int j = 2; i * j < n; j++) {
                prime[i * j] = false;
            }
        }
        
        return count;
    }
};
