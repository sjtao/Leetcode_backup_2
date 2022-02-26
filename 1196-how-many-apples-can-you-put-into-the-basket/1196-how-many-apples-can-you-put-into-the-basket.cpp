class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int sum = 0;
        int apple = 0;
        for(int w : weight){
            sum += w;
            if(sum > 5000){
                break;
            }
            apple++;
        }
        return apple;
    }
};