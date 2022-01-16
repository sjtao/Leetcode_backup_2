class Solution {
public:
    int minSwaps(vector<int>& data) {
        //sliding window with two pointers
        int n = data.size();
        int ones = 0; //window width
        for(int a : data)
            ones += a;
        
        int left = 0, right = 0;
        int cnt = 0, mx = 0;
        while(right < n){
            cnt += data[right++];
            if(right - left > ones)
                cnt -= data[left++];
            mx = max(mx, cnt);
        }
        return ones-mx;
    }
};