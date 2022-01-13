class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1;
        int high=nums.size()-1;
        int mid;
        while(low<high){
            mid=low + (high-low)/2;
            int count=0;
            for(int num:nums){
                if(num<=mid) count++;
            }
            if(count>mid) high=mid;//repeat number existed 
            else low=mid+1; 
        }
        return low;
    }
};