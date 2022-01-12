class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        //Brian Kernighan's algorithm
        while(left < right){
            right = right & (right-1);
        }
        return left & right;
    }
};