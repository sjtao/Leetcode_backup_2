class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int boat = 0;
        int weight = 0;
        int l = 0;
        int r = n-1;
        while(r > l){
            int d = people[r] + people[l++];
            //while(d < limit && l < r){
            //    d += people[l++];
            //}
            boat++;
            if(d > limit){      
                l--;
            }
            r--;
        }
        
        return r == l ? boat+1 : boat;
        
    }
};