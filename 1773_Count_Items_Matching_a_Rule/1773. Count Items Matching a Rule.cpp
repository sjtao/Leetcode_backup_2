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


//Runtime: 76 ms, faster than 54.72% of C++ online submissions for Count Items Matching a Rule.
//Memory Usage: 31 MB, less than 40.44% of C++ online submissions for Count Items Matching a Rule.

class Solution {
private:
    unordered_map<string, int> mp = {{"type", 0}, {"color", 1}, {"name", 2}};

public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int index = mp[ruleKey];
        for(int i = 0; i < items.size(); i++){
            if(items[i][index] == ruleValue)
                count += 1;
        }
        return count;
    }
};
