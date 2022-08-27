class Solution {
public:
    int bits(int n){
        int b = 0;
        while(n){
            b++;
            n &= (n-1);
        }
        return b;
    }
    vector<int> countBits(int n) {
        vector<int> count(n+1);
        for(int i = 0; i <= n; i++)
            count[i] = bits(i);
        return count;
    }
};