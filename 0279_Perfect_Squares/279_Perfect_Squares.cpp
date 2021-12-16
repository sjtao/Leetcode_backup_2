/**
Runtime: 139 ms, faster than 67.38% of C++ online submissions for Perfect Squares.
Memory Usage: 26.3 MB, less than 14.19% of C++ online submissions for Perfect Squares.
*/

class Solution {
public:
    int numSquares(int n) {
        queue<int> qe;
        vector<int> vec;
        unordered_set<int> visited;
        
        int step = 1;
        int i;
        for(i = 1; i*i <= n; i++){
            qe.push(i*i);
            vec.push_back(i*i);
            visited.insert(i*i);
        }
        
        if((i-1)*(i-1) == n) return step;
        
        while(!qe.empty()){
            int size = qe.size();
            step ++;
            
            for(i = 0; i < size; i++){
                int num = qe.front(); qe.pop();
                for(int k : vec){
                    int sum = num + k;
                    if(sum == n) return step;
                    else if (sum < n && visited.find(sum)==visited.end()){
                        qe.push(sum);
                        visited.insert(sum);
                    }
                }
            }
            
            
        }
        
        return -1;
    }
};
