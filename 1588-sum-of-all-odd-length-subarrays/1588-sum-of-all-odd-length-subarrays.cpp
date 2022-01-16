class Solution {
public:
    int vectorsum(vector<int>& arr){
        int sum = 0;
        if(arr.size() % 2 == 1){
            for(int a:arr)
                sum += a;
        }
        return sum;
    }
    
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        vector<int> sub;
        for(int i = 0; i < n; i++){
            int loc_sum = arr[i];
            sub.push_back(arr[i]);
            for(int j = i+1; j < n; j++){
                sub.push_back(arr[j]);
                loc_sum += vectorsum(sub);
            }
            sub.clear();
            sum += loc_sum;
        }
        return sum;
    }
};