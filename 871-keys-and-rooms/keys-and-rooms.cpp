class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& Rooms) {
        int n = Rooms.size();
        if(Rooms[0].empty() || n==0) return false;
        if(n==1) return true;

        vector<bool>Rooms_Bool(n,false);
        stack<int>Stk;
        int Curr_Room;
        Rooms_Bool[0]=true;

        for(int X : Rooms[0]){
            Stk.push(X);
        }
        

        while(!Stk.empty()){
            Curr_Room = Stk.top();  
            Rooms_Bool[Curr_Room]=true;  
            Stk.pop();
            for(int X : Rooms[Curr_Room]){
               if(!Rooms_Bool[X]) Stk.push(X);
            }
        }

    for(int i=0 ; i<n ; i++){
        if(Rooms_Bool[i]==false){
            return false;
        }
    }
    return true;
    }
};