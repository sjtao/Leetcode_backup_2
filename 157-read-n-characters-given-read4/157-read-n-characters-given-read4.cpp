/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        int r = 4; //everytime read 4 characters
        char buf4[4];
        while(ans < n && r == 4){
            r = read4(buf4);
            
            //copy to buf
            for(int i = 0; i < r; i++){
                if(ans == n)
                    return ans;
                buf[ans] = buf4[i];
                ans++;
            }
        }
        return ans;
    }
};