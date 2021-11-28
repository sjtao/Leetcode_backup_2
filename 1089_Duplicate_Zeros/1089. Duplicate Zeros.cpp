/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Duplicate Zeros.
Memory Usage: 9.8 MB, less than 25.20% of C++ online submissions for Duplicate Zeros.
*/

class Solution {
public:
    
    void duplicateZeros(vector<int>& arr) {
        // fixed-length integer array arr
        // 1 0 2 3 0 4 5 0 | 0 0 0
        //               i       r
        // 1 0 0 2 3 0 0 4 | 5 0 0
        int len = arr.size();
        int r = len + count(arr.begin(), arr.end(), 0) - 1;

        for(int i = len-1; i >= 0; i--){
            if(r >= len){
                if(arr[i] == 0){
                    r -= 2;
                }
                else{
                    r -= 1;
                }
                if(r < len-1) //there is a zero at the boundary and duplicate it will cause 0|0
                    arr[len-1] = 0;
            }
            else{
                arr[r] = arr[i];
                r -= 1;
                if(arr[i] == 0){
                    arr[r] = arr[i];
                    r -= 1; 
                }
            }
        }
    }
};
