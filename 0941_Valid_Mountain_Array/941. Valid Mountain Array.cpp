/**
Runtime: 32 ms, faster than 42.72% of C++ online submissions for Valid Mountain Array.
Memory Usage: 22.5 MB, less than 46.58% of C++ online submissions for Valid Mountain Array.
*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int s = arr.size();
        if(s < 3) return false;
        
        //left of i: strictly increase
        //right of i: strictly decrease
        int i;
        for(i = 0; i < s-1; i++){
            if(arr[i] == arr[i+1]){
                return false;
            }
            if(arr[i] > arr[i+1]){
                break;
            }
        }
        
        if(i == 0 || i == s-1){
            return false; //peak at beginning or end
        }
        
        for(int j = i; j < s-1; j++){
            if(arr[j] <= arr[j+1]){
                return false;
            }
        }
        
        return true;
    }
};
