class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 1);
        vector<int> coloumn(m, 1);

    // To find which rows & coloumns contain zeros
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    coloumn[j] = 0;
                }
            }
        }

    // To set rows and coloumns to zero
       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] == 0 || coloumn[j] == 0){
                matrix[i][j] = 0;
            }
         }
       }
    }
};