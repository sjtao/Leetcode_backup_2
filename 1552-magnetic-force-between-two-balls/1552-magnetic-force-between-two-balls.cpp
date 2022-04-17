class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int n = position.size();
        int left = 0;
        int right = position[n-1] - position[0];
        
        while(left <= right){
            int mid = left + (right-left)/2;
            int cnt = 1;
            int s = position[0];
            for(int i = 1; i < n; i++){
                if(position[i] - s >= mid){
                    cnt++;
                    s = position[i];
                }
            }
            if(cnt >= m)
                left = mid+1;
            else
                right = mid-1;
        }
        return left-1;
    }
};