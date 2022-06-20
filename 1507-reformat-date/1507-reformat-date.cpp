class Solution {
public:
    unordered_map<string, string> mp = {{"Jan","01"}, {"Feb","02"}, {"Mar","03"}, {"Apr","04"}, 
                                     {"May","05"}, {"Jun","06"}, {"Jul","07"}, {"Aug","08"}, 
                                     {"Sep","09"}, {"Oct","10"}, {"Nov","11"}, {"Dec","12"}};
    
    string reformatDate(string date) {

        int n = date.length();
        if(n == 12)
            date = "0" + date;
        
        int i = 0;
        string d = date.substr(i, 2);
        
        i+=5;
        string mon = date.substr(i, 3);
        
        i+=4;        
        string year = date.substr(i, 4);
        
        string ans = year + "-" + mp[mon] + "-" + d;
        return ans;
    }
};