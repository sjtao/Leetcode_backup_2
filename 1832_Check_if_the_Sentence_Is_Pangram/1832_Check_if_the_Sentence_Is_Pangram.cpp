
//Runtime: 4 ms, faster than 64.48% of C++ online submissions for Check if the Sentence Is Pangram.
//Memory Usage: 6.6 MB, less than 42.49% of C++ online submissions for Check if the Sentence Is Pangram.
class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26) return false;
        unordered_map<char, int> alphabet;
        for(auto s : sentence){
            alphabet[s] = 1;
        }
        for(int i = 0; i < 26; i++){
            if(alphabet[i+'a']==0){
                return false;
            }
        }
        return true;
    }
};

//Runtime: 4 ms, faster than 64.48% of C++ online submissions for Check if the Sentence Is Pangram.
//Memory Usage: 6.7 MB, less than 22.32% of C++ online submissions for Check if the Sentence Is Pangram.
class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26) return false;
        unordered_map<char, int> alphabet;
        for(auto s : sentence){
            alphabet[s] = 1;
        }
        if(alphabet.size() != 26)
            return false;
        return true;
    }
};
