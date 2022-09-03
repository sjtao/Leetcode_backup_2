class Solution {
public:
    vector<int> res;
    void consec(int a, int k, int len){
        if(len == 0){
            res.push_back(a);
            return;
        }
        
        int b = a % 10 + k;
        int s = a % 10 - k;
        if(b < 10)
            consec(a * 10 + b, k, len-1);
        
        if(b != s && s >= 0)
            consec(a * 10 + s, k, len-1);
        
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i < 10; i++)
            consec(i, k, n-1);
        return res;
    }
};