class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>Directions={{-1,0},{1,0},{0,-1},{0,1}};

        int Fresh_Oranges=0;
        queue<pair<int,int>>BFS_Q;
        int Minutes=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if (grid[i][j]==1){
                    Fresh_Oranges++;
                }else if(grid[i][j]==2){
                    BFS_Q.push({i,j});
                }
            }
        }

            int Q_Size;
            int New_i,New_j;
            while(!BFS_Q.empty() && Fresh_Oranges>0){
                Q_Size = BFS_Q.size();
                for(int k=0 ; k<Q_Size ; k++){
                    auto [i , j] = BFS_Q.front();
                    BFS_Q.pop();
                    for( auto& Dir : Directions){
                        New_i = i + Dir[0], New_j = j + Dir[1];
                        //Check Bounds and Fresh Orange
                        if(New_i>=0 && New_i<m && New_j>=0 && New_j<n && grid[New_i][New_j]==1){
                            BFS_Q.push({New_i,New_j});
                            grid[New_i][New_j]=2;
                            Fresh_Oranges--;
                        }
                    } // For Loop End Clause (Directions Check)
                    
                } // For Loop End Clause (Checking Adjacent Oranges k Check)
                Minutes++;
            }//While loop End Clause
            return ( (Fresh_Oranges==0) ?  Minutes:-1);
    }
};