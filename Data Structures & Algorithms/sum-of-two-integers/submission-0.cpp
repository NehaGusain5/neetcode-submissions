class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
        unsigned carry = (unsigned)(a & b) << 1; // calculate carry
        a = a ^ b;  // sum without carry
        b = carry;  // add carry
    }
    return a;
    }
};
