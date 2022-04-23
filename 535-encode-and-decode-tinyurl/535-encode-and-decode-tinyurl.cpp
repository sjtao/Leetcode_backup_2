class Solution {
public:
    unordered_map<int, string> mp;
    int id = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mp[id] = longUrl;
        return "http://tinyurl.com/" + to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int idx = 0;
        for(char c : shortUrl){
            if(isdigit(c)){
                int a = c - '0';
                idx = idx * 10 + a;
            }
        }
        return mp[idx];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));