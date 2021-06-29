class Solution {
public:
    int trailingZeroes(int n) {
        int two = 0;
        int five = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = i;
            while (1) {
                if (tmp % 2 == 0) { two += 1; tmp /= 2; }
                else if (tmp % 5 == 0) { five += 1; tmp /= 5; }
                else { break; }
            }
        }
        return min(two, five);
    }
};
