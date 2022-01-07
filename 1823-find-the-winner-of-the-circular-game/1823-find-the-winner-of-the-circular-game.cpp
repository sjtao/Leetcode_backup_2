class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> qe;
        
        for(int i = 1; i <= n; i++)
            qe.push(i);
        int c, t;
        while(qe.size() > 1){
            c = 1;
            while(c < k){
                t = qe.front(); qe.pop();
                qe.push(t);
                c++;
            }
            qe.pop();
        }
        
        return qe.front();

    }
};