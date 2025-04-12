class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int Edges = connections.size();
        vector<vector<pair<int,string>>>Graph(n);
        int U,V;
        for( int i=0 ; i<Edges ; i++){
            U=connections[i][0];
            V=connections[i][1];
            Graph[U].push_back({V,"OutWard"});
            Graph[V].push_back({U,"InWard"});
        }

        vector<bool>Visited_Nodes(n,false);
        stack<int>Stk;
        Stk.push(0);
        int Changes_Needed=0;
        int Curr_Node;

        while(!Stk.empty()){
            Curr_Node = Stk.top();
            Stk.pop();
            Visited_Nodes[Curr_Node]=true;
            for(auto& [Neighbor,Direc] : Graph[Curr_Node]){
                if(!Visited_Nodes[Neighbor]){
                    if(Direc=="OutWard")Changes_Needed++;
                    Stk.push(Neighbor);
                }
            }
        }
        return Changes_Needed;
    }
};