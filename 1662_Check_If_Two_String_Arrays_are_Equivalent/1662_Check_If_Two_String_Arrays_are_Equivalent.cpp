//Runtime: 8 ms, faster than 35.21% of C++ online submissions for Check If Two String Arrays are Equivalent.
//Memory Usage: 11.4 MB, less than 76.22% of C++ online submissions for Check If Two String Arrays are Equivalent.

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        //Concatenate all strings in the array into a single string in the given order
        for(int i = 0; i<word1.size(); i++){
            a += word1[i];
        }
        for(int i = 0; i<word2.size(); i++){
            b += word2[i];
        }
        //compare
        return (a==b);
    }
};
