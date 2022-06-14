class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0, cur = 0, next = 0;
        for(int i = 0; i < n; i++){
            tank += (gas[i] - cost[i]);
            cur  += (gas[i] - cost[i]);
            if(cur < 0){
                next = i+1;
                cur = 0;
            }
        }
        
        return tank >= 0 ? next : -1;
    }
};