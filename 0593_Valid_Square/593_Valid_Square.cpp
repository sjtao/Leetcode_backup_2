/**
Runtime: 4 ms, faster than 86.29% of C++ online submissions for Valid Square.
Memory Usage: 26.5 MB, less than 96.33% of C++ online submissions for Valid Square.
*/
class Solution {
public:
    bool squareHelper(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        int a = (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
        int b = (p3[0] - p2[0])*(p3[0] - p2[0]) + (p3[1] - p2[1])*(p3[1] - p2[1]);
        int c = (p3[0] - p1[0])*(p3[0] - p1[0]) + (p3[1] - p1[1])*(p3[1] - p1[1]);
        
        if(a != 0 && b != 0 && c != 0){
            if((a == b && a+b == c) || (b == c && b+c == a) || (a == c && a+c == b))
                return true;
        }
        
        
        return false;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return squareHelper(p1, p2, p3) && squareHelper(p2, p3, p4) && squareHelper(p1, p3, p4);
    }
};
