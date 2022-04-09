class Solution {
public:
    int specialArray(vector<int>& nums) {
        //counting sort
        vector<int> count(1002, 0);
        for(int& n : nums){
            count[n]++;
        }
        
        for(int i = 1000; i >= 0; i--){
            count[i] += count[i+1];
            if(count[i] == i)
                return i;
        }
        
        return -1;
    }
};