class Solution {

public:
    
int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int,int>>>Graph(n);

    for(auto& Conn : connections){
        Graph[Conn[0]].push_back({Conn[1],1});
        Graph[Conn[1]].push_back({Conn[0],0});
    }

    vector<bool>Visited(n,false);

    queue<int>Q_BFS;

    Q_BFS.push(0);
    Visited[0]=true;
    int Changes=0;
    int Curr_Node;
    while(!Q_BFS.empty()){
        Curr_Node=Q_BFS.front();
        Q_BFS.pop();

        for(auto& [Neighbor,ChangeNeed] : Graph[Curr_Node]){
            if(!Visited[Neighbor]){
                Changes+=ChangeNeed;
                Visited[Neighbor]=true;
                Q_BFS.push(Neighbor);
            }
        }
    }
      return Changes;
}

};



// DFS Iterative Approach ;  Time: O(N) ,  Space: O(N)
/*
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

*/



// DFS Recursive Approach ;  Time: O(N) ,  Space: O(N)

/*
void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int& changes) {
    visited[node] = true;

    for (auto& [neighbor, needsChange] : graph[node]) {
        if (!visited[neighbor]) {
            changes += needsChange;
            dfs(neighbor, graph, visited, changes);
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto& conn : connections) {
        graph[conn[0]].push_back({conn[1], 1});
        graph[conn[1]].push_back({conn[0], 0});
    }

    vector<bool> visited(n, false);
    int changes = 0;
    dfs(0, graph, visited, changes);
    return changes;
}
*/