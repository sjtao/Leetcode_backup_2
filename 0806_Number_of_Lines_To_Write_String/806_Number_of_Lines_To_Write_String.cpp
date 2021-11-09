//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Lines To Write String.
//Memory Usage: 7 MB, less than 44.30% of C++ online submissions for Number of Lines To Write String.

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int pixel = 0;
        for(int i = 0; i < s.length(); i++){
            pixel += widths[s[i]-'a'];
            if(pixel > 100){
                pixel = widths[s[i]-'a'];
                line ++;
            }
        }
        vector<int> ans;
        ans.push_back(line);
        ans.push_back(pixel);
        return ans;
    }
};
