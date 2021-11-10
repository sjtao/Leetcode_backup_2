//Runtime: 8 ms, faster than 36.85% of C++ online submissions for Counting Bits.
//Memory Usage: 8.4 MB, less than 32.45% of C++ online submissions for Counting Bits.

class Solution {
public:
    int binaryOne(int a){
        int cnt = 0;
        while(a > 0){
            if (a % 2 == 1){
                cnt ++;
            }
            a = a/2;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i < n+1; i++){
            ans.push_back(binaryOne(i));
        }
        
        return ans;
    }
};
