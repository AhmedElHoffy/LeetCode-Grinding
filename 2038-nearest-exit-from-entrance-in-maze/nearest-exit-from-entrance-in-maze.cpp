class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int Row_Size = maze.size(), Col_Size = maze[0].size();
        vector<vector<int>>Directions={{-1,0},{1,0},{0,-1},{0,1}}; //Up,Down,Left,Right
        int Min_Num_Steps = 0;
        bool Exit_Found=false;


        queue<tuple<int,int,int>>BFS_Q;
        BFS_Q.push({entrance[0],entrance[1],0});
        maze[entrance[0]][entrance[1]]='+';
        int New_i , New_j;

        while(!BFS_Q.empty()){
            auto [i , j , Curr_Steps] = BFS_Q.front();
            BFS_Q.pop();
            for(auto& Dir : Directions){
                New_i = i + Dir[0];
                New_j = j + Dir[1];

                // Check bounds and Walls
                if(New_i>=0 && New_i<Row_Size && New_j>=0 && New_j<Col_Size && maze[New_i][New_j]=='.'){
                    //Check if it is an exit
                    if(New_i==0 || New_i==Row_Size-1  || New_j==0 || New_j==Col_Size-1){
                        return Curr_Steps+1;
                    }
                    BFS_Q.push({New_i,New_j,Curr_Steps+1});
                    maze[New_i][New_j]='+';
                }
            }
        }

        return -1;
    }
};