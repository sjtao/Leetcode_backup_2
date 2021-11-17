//Runtime: 64 ms, faster than 5.16% of C++ online submissions for Ransom Note.
//Memory Usage: 8.6 MB, less than 90.48% of C++ online submissions for Ransom Note.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r = ransomNote.length();
        int m = magazine.length();
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < magazine.length(); j++){
                if(ransomNote[i] == magazine[j]){
                    magazine.erase(j, 1);
                    break;
                }
            }
        }
        return (m - magazine.length() == r);
    }
};

//Runtime: 20 ms, faster than 51.61% of C++ online submissions for Ransom Note.
//Memory Usage: 8.9 MB, less than 14.51% of C++ online submissions for Ransom Note.
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> ran;
        
        for(int i = 0; i < magazine.length(); i++){
            ran[magazine[i]]++;
        }
        
        for(int i = 0; i < ransomNote.length(); i++){
            if(ran.find(ransomNote[i]) == ran.end()){
                return false;
            }
            else{
                ran[ransomNote[i]]--;
                if(ran[ransomNote[i]] < 0){
                    return false;
                }
            }
        }
        
        return true;
    }
};
