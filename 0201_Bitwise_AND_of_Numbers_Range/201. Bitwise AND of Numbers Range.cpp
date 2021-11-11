//Runtime: 8 ms, faster than 71.96% of C++ online submissions for Bitwise AND of Numbers Range.
//Memory Usage: 5.9 MB, less than 33.72% of C++ online submissions for Bitwise AND of Numbers Range.

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return right;
        if(left == 0) return 0;
        // 15: 0000 1111
        // 16: 0001 0000
        // 17: 0001 0001
        // 18: 0001 0010
        // 19: 0001 0011
        // 20: 0001 0100
        //-------------------
        //     0000 0000
        int shift = 0;
        while(left && left != right){
            left = left >> 1;
            right = right >> 1;
            shift ++;
        }
        
        return (left << shift);
        
    }
};
