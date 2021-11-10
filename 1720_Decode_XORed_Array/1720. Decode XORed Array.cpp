//Runtime: 28 ms, faster than 73.30% of C++ online submissions for Decode XORed Array.
//Memory Usage: 24.9 MB, less than 86.73% of C++ online submissions for Decode XORed Array.

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> a(encoded.size()+1, 0);
        a[0] = first;
        
        //c = a^b
        //b = c^a
        //a = c^b
        for(int i = 1; i <encoded.size()+1; i++){
            a[i] = encoded[i-1] ^ a[i-1];
        }
        return a;
    }
};
