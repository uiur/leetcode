
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> checked;
        while (n > 0) {
            if (n == 1) return true;
            if (checked.find(n) != checked.end()) return false;
            checked.insert(n);
            
            int sum = 0;
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10; 
            }
            n = sum; 
        }
        return false;
    }
};
