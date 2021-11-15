//Runtime: 80 ms, faster than 41.35% of C++ online submissions for Count Items Matching a Rule.
//Memory Usage: 30.9 MB, less than 77.86% of C++ online submissions for Count Items Matching a Rule.

class Solution {
public:
    
    int countHelper(vector<string>&item, string ruleKey, string ruleValue){
        if((ruleKey == "type" && ruleValue == item[0]) 
        || (ruleKey == "color" && ruleValue == item[1])
        || (ruleKey == "name" && ruleValue == item[2])){
            return 1;
        }
        return 0;
    }
    
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for(int i = 0; i < items.size(); i++){
            count += countHelper(items[i], ruleKey, ruleValue);
        }
        return count;
    }
};
