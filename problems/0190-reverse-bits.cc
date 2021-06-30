// Runtime: 4 ms, faster than 54.85% of C++ online submissions for Reverse Bits.
// Memory Usage: 5.7 MB, less than 96.02% of C++ online submissions for Reverse Bits.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result = result << 1;
            result |= n & 1;
            n = n >> 1;
        }
        
        return result;
    }
};
