class Solution {
public:
    int countBits(int a){
        int count = 0;
        while(a){
            count += (a & 1);
            a >>= 1;
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        for(int a : arr)
            q.push({countBits(a), a});
        
        for(int i = 0; i < arr.size(); ++i){
            arr[i] = q.top().second;
            q.pop();
        }
            
        return arr;
    }
};