class Solution {
private: 
        void dfs(vector<vector<int>>& rooms , int curr_room , vector<bool>&visited){
            visited[curr_room] = true;
            int key_found;
            for(int i=0 ; i <rooms[curr_room].size() ; i++){
                key_found = rooms[curr_room][i];
                if(visited[key_found]==false){
                    dfs(rooms,key_found,visited); // visit the next room
                }
            }
        }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>Visited(n,false);
        dfs(rooms,0,Visited);

        for(bool v : Visited){
            if(!v)return false;
        }
        return true;
    }
};