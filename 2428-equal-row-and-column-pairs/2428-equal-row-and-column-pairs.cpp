class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int rows_Size = grid.size();
        int Cols_Size = grid[0].size();
        multiset<vector<int>>Rows_Elements_Set;
        multiset<vector<int>>Columns_Elements_Set;

        int count=0;
        
        for(int i=0 ; i < rows_Size; i++){
            Rows_Elements_Set.insert(grid[i]);
        }


        vector<int>Curr_Col(Cols_Size,0);
        for(int j = 0 ;  j < Cols_Size ; j++){
             vector<int>Curr_Col(Cols_Size);
            for(int i=0 ; i < rows_Size ; i++){
                Curr_Col[i]=grid[i][j];
            }
            Columns_Elements_Set.insert(Curr_Col);
        }

        for(auto vec : Rows_Elements_Set ){
                count+=Columns_Elements_Set.count(vec);
        }
        return count;

    }
};































/*


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); // Size of the matrix
        map<vector<int>, int> row_map; // Map to store row vectors and their frequencies

        // Step 1: Store rows in the map
        for (int i = 0; i < n; i++) {
            row_map[grid[i]]++; // grid[i] is the row as a vector<int>
        }

        int count = 0;

        // Step 2: Compare columns with rows
        for (int j = 0; j < n; j++) {
            vector<int> col_vector;
            for (int i = 0; i < n; i++) {
                col_vector.push_back(grid[i][j]); // Extract column as a vector
            }
            if (row_map.find(col_vector) != row_map.end()) {
                count += row_map[col_vector]; // Add the frequency of matching rows
            }
        }

        return count;     
    }
};




*/