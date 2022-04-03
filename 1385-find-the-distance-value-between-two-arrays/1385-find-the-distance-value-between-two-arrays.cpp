class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int cnt = 0;
        sort(arr2.begin(), arr2.end());
        for(int i = 0; i < n1; ++i){
            int l = 0, r = n2-1, m;
            bool add = true;
            while(l <= r){
                m = l + (r - l) / 2;
                if(abs(arr2[m] - arr1[i]) <= d){
                    add = false;
                    break;
                }
                else if(arr2[m] > arr1[i])
                    r = m -1;
                else
                    l = m + 1; 
            }
            if(add)
                cnt++;
        }
        return cnt;
    }
};