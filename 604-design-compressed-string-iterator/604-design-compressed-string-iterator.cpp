class StringIterator {
public:
    vector<pair<char, int>> input;
    int size;
    int idx;
    StringIterator(string compressedString) {
        int i = 0;
        while(i < compressedString.length()){
            char c = compressedString[i++];
            int num =  0;
            while(i < compressedString.length() && isdigit(compressedString[i])){
                num = num * 10 + (compressedString[i] - '0');
                i++;
            }
            input.push_back({c, num});
        }
        size = input.size();
        idx = 0;
    }
    
    char next() {
        if(!hasNext())
            return ' ';
        char ans = input[idx].first;
        input[idx].second--;
        if(input[idx].second == 0)
            idx ++;

        return ans;
    }
    
    bool hasNext() {
        return idx != size;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */