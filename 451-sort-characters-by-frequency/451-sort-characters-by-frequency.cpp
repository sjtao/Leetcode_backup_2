class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;           //for frequency of characters
        priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
        
        for(char c : s)
            freq[c]++;
        
        for(auto it : freq)
            maxheap.push({it.second, it.first});
        
        string ans = "";
        while(!maxheap.empty()){
            auto m = maxheap.top();
            for(int i = 0; i < m.first; i++)
                ans += m.second;
            maxheap.pop();
        }
        
        return ans;
    }
};