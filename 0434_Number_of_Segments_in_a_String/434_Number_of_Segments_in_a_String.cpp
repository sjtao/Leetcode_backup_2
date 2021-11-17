//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Segments in a String.
//Memory Usage: 6.2 MB, less than 11.93% of C++ online submissions for Number of Segments in a String.

class Solution {
public:
    int countSegments(string s) {
        if(s.length() == 0) return 0;
        
        int start = 0;
        int end = s.length();
        
        int seg=0;
        for(int i = start; i < end; i++){
            if(s[i] != ' '){
                while(s[i] != ' ' && i < end)
                    i++;
                seg ++;
            }
        }
        
        return seg;
    }
};
