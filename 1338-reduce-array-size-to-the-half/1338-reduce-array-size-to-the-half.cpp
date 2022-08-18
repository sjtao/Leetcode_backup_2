class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int half = n/2;
        
        unordered_map<int, int> mp;
        for(int a : arr)
            mp[a]++;
        
        priority_queue<int, vector<int>> p;
        for(auto& it : mp)
            p.push(it.second);
        
        int k = 0;
        while(n > half){
            n -= p.top();
            p.pop();
            k++;
        }
        
        return k;
    }
};