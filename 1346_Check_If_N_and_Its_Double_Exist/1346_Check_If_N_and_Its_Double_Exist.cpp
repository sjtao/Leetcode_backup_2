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


/**
Runtime: 4 ms, faster than 94.14% of C++ online submissions for Check If N and Its Double Exist.
Memory Usage: 10.6 MB, less than 21.67% of C++ online submissions for Check If N and Its Double Exist.
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> marr;
        //save all the even numbers to a map
        for(int a: arr){
            if(a % 2 == 0)
                marr[a]++;
        }
        //find
        for(int a:arr){
            if(a != 0 && marr.find(2*a) != marr.end()){
                return true;
            }
            if(a == 0 && marr[0] > 1){
                return true;
            }
        }
        return false;
    }
};
