class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0) return;
        int update = 0;
        for(int i = 0; i < k && update < n; i++){
            int oldi = nums[i];
            int oldn;
            int start = i;
            do{
                int next = (start+k) % n;
                int oldn = nums[next];
                nums[next] = oldi;
                
                oldi = oldn;
                start = next;
                update++;
            }while(start != i);
        }
        
        return;
    }
};