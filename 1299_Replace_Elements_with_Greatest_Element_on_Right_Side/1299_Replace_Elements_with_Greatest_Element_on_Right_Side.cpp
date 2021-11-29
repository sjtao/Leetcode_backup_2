/**
Runtime: 12 ms, faster than 91.40% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
Memory Usage: 14.5 MB, less than 65.76% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size()-1;
        
        int mx = arr[len];
        int mx_o;
        arr[len] = -1;
        
        for(int i = len-1; i>= 0; i--){
            mx_o = mx;
            mx = max(arr[i], mx);
            arr[i] = mx_o; 
        }
        
        return arr;
    }
};
