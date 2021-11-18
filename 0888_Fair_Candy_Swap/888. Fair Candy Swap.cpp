
//75 / 75 test cases passed, but took too long.
//brutal force
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        // sa - a + b = sb - b + a
        // b = a + (sb - sa) / 2
        vector<int> ans;
        
        int alice = 0;
        for(int i = 0; i < aliceSizes.size(); i++){
            alice += aliceSizes[i];
        }
        int bob = 0;
        for(int i = 0; i < bobSizes.size(); i++){
            bob += bobSizes[i];
        }
        int delta = (bob - alice) / 2;
        bool find = 0;
        for(int i = 0; i < aliceSizes.size(); i++){
            for(int j = 0; j < bobSizes.size(); j++){
                if(bobSizes[j] == aliceSizes[i] + delta){
                    ans.push_back(aliceSizes[i]);
                    ans.push_back(bobSizes[j]);
                    find = 1;
                    break;
                }
            }
            if(find)
                break;
        }
        return ans;
    }
};

//Runtime: 108 ms, faster than 52.45% of C++ online submissions for Fair Candy Swap.
//Memory Usage: 50.5 MB, less than 25.61% of C++ online submissions for Fair Candy Swap.

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        // sa - a + b = sb - b + a
        // b = a + (sb - sa) / 2
        vector<int> ans;
        
        int alice = 0;
        for(int i : aliceSizes){
            alice += i;
        }
        int bob = 0;
        for(int i : bobSizes){
            bob += i;
        }
        int delta = (bob - alice) / 2;
       
        set<int> bobset;
        for(int i : bobSizes)
            bobset.insert(i);
        
        for(int a : aliceSizes){
            if(bobset.find(a + delta)!=bobset.end()){
                ans.push_back(a);
                ans.push_back(a + delta);
                break;
            }
                
        }
        
        
        return ans;
    }
};
