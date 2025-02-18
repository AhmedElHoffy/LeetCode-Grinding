class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); // n x n matrix
        multiset<vector<int>> Rows_Elements_Set, Columns_Elements_Set;
        int count = 0;

        // Store row vectors in multiset
        for (int i = 0; i < n; i++) {
            Rows_Elements_Set.insert(grid[i]);
        }

        // Store column vectors in multiset
        for (int j = 0; j < n; j++) {
            vector<int> Curr_Col(n);
            for (int i = 0; i < n; i++) {
                Curr_Col[i] = grid[i][j]; // Corrected indexing
            }
            Columns_Elements_Set.insert(Curr_Col);
        }

        // Count matching row and column vectors
        for (const auto& vec : Rows_Elements_Set) {
            count += Columns_Elements_Set.count(vec);
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