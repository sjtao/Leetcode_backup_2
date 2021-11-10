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

//Runtime: 4 ms, faster than 88.58% of C++ online submissions for Counting Bits.
//Memory Usage: 7.7 MB, less than 98.07% of C++ online submissions for Counting Bits.
class Solution {
public:
    // 6: 110
    //12: 110 0
    //13: 110 1
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i = 1; i < n+1; i++){
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};
