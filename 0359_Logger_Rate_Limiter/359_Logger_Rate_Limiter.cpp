/**
Runtime: 72 ms, faster than 57.84% of C++ online submissions for Logger Rate Limiter.
Memory Usage: 32.4 MB, less than 67.12% of C++ online submissions for Logger Rate Limiter.
*/
class Logger {
public:
    unordered_map<string, int> mp;
    Logger() {
        mp.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.count(message)){
            if(timestamp >= mp[message]+10){
                mp[message] = timestamp;
                return true;
            }   
        }
        else{
            mp[message] = timestamp;
            return true;
        }
        
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
