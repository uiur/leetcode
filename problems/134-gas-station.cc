// Runtime: 164 ms, faster than 15.37% of C++ online submissions for Gas Station.
// Memory Usage: 9.8 MB, less than 49.47% of C++ online submissions for Gas Station.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            int t = 0;
            for(int j = 0; j < n; j++) {
                t += gas[(i+j) % n] - cost[(i+j) % n];
                if (t < 0) break;
            }
            if (t >= 0) return i;
        }
        return -1;
    }
};
