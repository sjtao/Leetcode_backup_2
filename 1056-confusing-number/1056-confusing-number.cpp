class Solution {
public:
    unordered_map<int, int> mp = {{0, 0}, {1,1},{2,-1},{3,-1},{4,-1},
                                  {5,-1},{6,9},{7,-1},{8,8},{9,6}};
    bool confusingNumber(int n) {
        int k = n;
        int r = 0;
        while(k > 0){
            int m = k % 10;
            if(mp[m] == -1)
                return false;
            k /= 10;
            r = 10 * r +  mp[m];

        }
        return r != n;
    }
};