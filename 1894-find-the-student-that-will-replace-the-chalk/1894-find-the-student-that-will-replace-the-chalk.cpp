class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int kcopy = k;
        int n = chalk.size();
        for(int i = 0; i < n; ++i){
            kcopy -= chalk[i];
            if(kcopy < 0)
                return i;
        }
        k %= (k - kcopy);
        for(int i = 0; i < chalk.size(); ++i){
            k -= chalk[i];
            if(k < 0)
                return i;
        }
        return -1;
    }
};