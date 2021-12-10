class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n <= k) return arr;
        
        //find out the lower bound of that k length range
        int low = 0, high = n-k, mid;
        while(low < high){
            mid = low + (high - low) / 2;
            if(x - arr[mid] > arr[mid+k] - x){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};
