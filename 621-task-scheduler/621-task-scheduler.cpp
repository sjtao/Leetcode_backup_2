class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s = tasks.size();
        if(n == 0) return s;
        
        vector<int> freq(26, 0);
        for(char c : tasks)
            freq[c-'A']++;
        
        int mx = 0;
        for(int f : freq)
            mx = max(mx, f);
        
        int nmx = 0;
        for(int f : freq)
            nmx += (f == mx);
        
        return max(s, (mx-1)*(n+1)+nmx);
    }
};