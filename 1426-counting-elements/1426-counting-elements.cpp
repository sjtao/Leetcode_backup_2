class Solution {
public:
    unordered_map<int,int> mp;
    int countElements(vector<int>& arr) {
        for(int a:arr){
            mp[a]++;
        }
        int n=0;
        for(int a:arr){
            if(mp.find(a+1) != mp.end()){
                n++;
            }
        }
        return n;
    }
};