class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        if(n <= 1) return n;
        
        vector<int> st(n), ed(n);
        for(int i = 0; i < n; ++i){
            st[i] = intervals[i][0];
            ed[i] = intervals[i][1];
        }
        sort(st.begin(), st.end());
        sort(ed.begin(), ed.end());
        
        //min-heap
        int s = 0, e = 0;
        int room = 0;
        while(s < n){
            if(st[s] >= ed[e]){
                e++;
                room -= 1;
            }
            room+=1;
            s+=1;
        }
        return room;
    }
};