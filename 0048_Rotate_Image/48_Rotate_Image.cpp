/**
Runtime: 4 ms, faster than 55.70% of C++ online submissions for Rotate Image.
Memory Usage: 7.2 MB, less than 30.50% of C++ online submissions for Rotate Image.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); //n*n matrix
        //transpose the matrix
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reflect the matrix
        int i = 0;
        int j = n-1;
        while(i < j){
            for(int k = 0; k < n; k++){
                swap(matrix[k][i], matrix[k][j]);
            }
            i++;
            j--;
        }
        return;
    }
};

/**
Runtime: 4 ms, faster than 55.70% of C++ online submissions for Rotate Image.
Memory Usage: 7.1 MB, less than 30.50% of C++ online submissions for Rotate Image.
*/
class Solution {
public:
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }
};
