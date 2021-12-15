/**
Runtime: 24 ms, faster than 50.18% of C++ online submissions for Jump Game II.
Memory Usage: 16.3 MB, less than 70.95% of C++ online submissions for Jump Game II.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int step = 1;
        int i = 0;
        int far;
        while(i < n-1){
            far = i + nums[i];
            if(far >= n-1)
                break;
            
            //find the max number in [i+1, far]
            int mx = -1;
            int id;
            for(int j = i+1; j <= far; j++){
                if(mx <= j+nums[j]){
                    mx = j+nums[j];
                    id = j;
                }
            }
            i = id;
            step ++;
        }
        
        return step;
    }
};

/**
Runtime: 362 ms, faster than 23.99% of C++ online submissions for Jump Game II.
Memory Usage: 17 MB, less than 27.74% of C++ online submissions for Jump Game II.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        //dp
        vector<int> step(n, INT_MAX);
        
        step[0] = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = min(n-1, i + nums[i]); j > i; j--){
                if(step[j] > step[i]+1)
                    step[j] = step[i]+1;
            }
        }
        
        return step[n-1];
    }
};

/**
Runtime: 265 ms, faster than 30.51% of C++ online submissions for Jump Game II.
Memory Usage: 17 MB, less than 27.74% of C++ online submissions for Jump Game II.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        //dp
        vector<int> step(n, INT_MAX);
        
        step[0] = 0;
        
        for(int i = 0; i < n; i++){
            int t = i + nums[i];
            if(t >= n-1){
                step[n-1] = step[i]+1;
                break;
            }
            else{
                for(int j = t; j > i; j--){
                    if(step[j] > step[i]+1)
                        step[j] = step[i]+1;
            }
            }
            
        }
        
        return step[n-1];
    }
};
