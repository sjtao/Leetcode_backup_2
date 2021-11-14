//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Final Value of Variable After Performing Operations.
//Memory Usage: 14 MB, less than 56.92% of C++ online submissions for Final Value of Variable After Performing Operations.

class Solution {
public:
    
    void operationHelper(string s, int &x){
        if(s == "++X" || s == "X++") 
            x += 1;
        else if(s == "--X" || s == "X--")
            x -= 1;
    }
    
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(int i = 0; i < operations.size(); i++){
            operationHelper(operations[i], x);
        }
        return x;
    }
};
