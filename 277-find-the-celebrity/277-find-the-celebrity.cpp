/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    bool iscelebrity(int i, int n){
        for(int j = 0; j < n; ++j){
            if(i == j)
                continue;
            if(knows(i,j) || !knows(j,i)){ //i knows j or j doesn't know i
                return false;
            }
        }
        return true;
    }
    
    int findCelebrity(int n) {
        int c = 0;
        for(int i = 0; i < n; i++){
            if(knows(c, i)){//c knows i, c is not celebrity
                c = i;
            }
        }
        
        if(iscelebrity(c, n))
            return c;
        
        return -1;
    }
};