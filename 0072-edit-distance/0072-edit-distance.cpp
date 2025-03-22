class Solution {
public:
    int minDistance(string word1, string word2) {

        int RowsLen = word1.size();
        int ColsLen = word2.size();

        vector<vector<int>>DP_Matrix(RowsLen+1,vector<int>(ColsLen+1,0));

        int Matrix_Row = RowsLen  + 1 ;
        int Matrix_Col = ColsLen  + 1 ;
        int temp_min;

        for (int j = Matrix_Col - 2; j >= 0; j--) {
            DP_Matrix[Matrix_Row - 1][j] = Matrix_Col - 1 - j; // Correct initialization
        }

        for (int i = Matrix_Row - 2; i >= 0; i--) {
            DP_Matrix[i][Matrix_Col - 1] = Matrix_Row - 1 - i; // Correct initialization
        }
        
        for(int i = Matrix_Row-2 ; i>=0 ; i--){
            for(int j = Matrix_Col -2  ; j>=0 ; j-- ){
                if(word1[i]==word2[j]){
                    DP_Matrix[i][j]= DP_Matrix[i+1][j+1];
                }else{
                    temp_min = min(DP_Matrix[i][j+1],DP_Matrix[i+1][j]);
                    DP_Matrix[i][j] = 1 + min(temp_min,DP_Matrix[i+1][j+1]);
                }
            }
        }
        return DP_Matrix[0][0];
    }
};