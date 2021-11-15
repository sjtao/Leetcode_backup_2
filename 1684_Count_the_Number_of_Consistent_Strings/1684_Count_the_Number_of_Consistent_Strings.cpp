//Runtime: 60 ms, faster than 60.57% of C++ online submissions for Count the Number of Consistent Strings.
//Memory Usage: 30.3 MB, less than 26.55% of C++ online submissions for Count the Number of Consistent Strings.

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> alw_set;
        
        for(char s: allowed){
            alw_set.insert(s);
        }
        
        int number = 0;
        bool find;
        for(auto s: words){
            find = 1;
            for(auto a: s){
                if(alw_set.count(a)==0){
                    find = 0;
                    break;
                }
            }
            if(find)
                number += 1;
        }
        
        return number;
    }
};
