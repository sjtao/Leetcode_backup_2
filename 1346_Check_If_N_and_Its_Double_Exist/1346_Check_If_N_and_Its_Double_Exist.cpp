/**
Runtime: 8 ms
Memory Usage: 10.1 MB
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        int len = arr.size();
        for(int i = 0; i < len; i++){
            int a2 = arr[i]*2;
            for(int j = 0; j < len; j++){
                if(i != j && arr[j] == a2){
                    return true;
                }
            }
        }
        
        return false;
    }
};
