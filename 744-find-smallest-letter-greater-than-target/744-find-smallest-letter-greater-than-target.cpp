class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size(), m;
        while(l < r){
            m = l + (r-l) / 2;
            if(letters[m] - target <= 0)
                l = m+1;
            else
                r = m;
        }
        return l == letters.size() ? letters[0] : letters[l];
    }
};