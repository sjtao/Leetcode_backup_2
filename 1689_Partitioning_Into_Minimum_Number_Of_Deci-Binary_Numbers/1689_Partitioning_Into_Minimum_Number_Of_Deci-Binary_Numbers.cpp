//Runtime: 32 ms, faster than 83.27% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
//Memory Usage: 13.6 MB, less than 16.88% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.

class Solution {
public:
    int minPartitions(string n) {
        
        //2345:  1111
        //       1111
        //       0111
        //       0011
        //       0001
        //-------------
        //       2345
        
        int ans = n[0] - '0'; 
        for(int i = 1; i < n.length(); i++){
            ans = ans > (n[i] - '0') ? ans : (n[i] - '0');
        }
        return ans;
    }
};
