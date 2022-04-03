class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int cnt = 0;
        sort(arr2.begin(), arr2.end());
        for(int i = 0; i < n1; ++i){
            int j = n2-1;
            for(; j >= 0; --j){
                if(abs(arr1[i] - arr2[j]) <= d)
                    break;
            }
            if(j < 0)
                cnt++;
        }
        return cnt;
    }
};