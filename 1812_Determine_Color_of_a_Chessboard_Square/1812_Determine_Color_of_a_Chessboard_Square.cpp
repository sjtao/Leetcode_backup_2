//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Determine Color of a Chessboard Square.
//Memory Usage: 5.9 MB, less than 66.25% of C++ online submissions for Determine Color of a Chessboard Square.

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int c = coordinates[0] - 'a' + 1;
        int n = coordinates[1] - '0';
        //black: coord[0] and coord[1] both even or both odd
        if((c % 2) == (n % 2)){
            return false;
        }
        
        return true;
    }
};
