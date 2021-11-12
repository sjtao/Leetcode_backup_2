
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
//Memory Usage: 6.4 MB, less than 24.81% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {        
        vector<int> diff;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                diff.push_back(i);
            }
        }
        if(diff.size() == 0) //s1 = s2
            return true;
        else if(diff.size() == 2){
            if(s1[diff[0]] != s2[diff[1]] || s1[diff[1]] != s2[diff[0]])
                return false;
            else
                return true;
        }
        else
             return false;
    }
};
