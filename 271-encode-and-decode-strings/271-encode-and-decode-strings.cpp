class Codec {
public:
    vector<int> len;
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs){
            ans += s;
            len.push_back(s.length());
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = len.size();
        vector<string> strs(n);
        int k = 0;
        for(int i = 0; i < n; i++){
            strs[i] = s.substr(k, len[i]);
            k += len[i];
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));