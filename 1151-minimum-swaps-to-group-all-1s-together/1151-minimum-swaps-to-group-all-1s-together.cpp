class Solution {
public:
    int minSwaps(vector<int>& data) {
        int total = 0;
        for(int d : data){
            total += d;
        }
        
        //two pointer; window size = total
        int cur = 0;
        int maxseen = 0;
        
        for(int i = 0; i < data.size(); i++){
            cur += data[i];
            if(i >= total){
                cur -= data[i-total];
            }
            maxseen = max(maxseen, cur);
        }
        
        return total - maxseen;
    }
};