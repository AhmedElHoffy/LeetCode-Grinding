class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>>Graph;
        string Numerator,Denomerator;
        double Val;
        
        //Building the Graph
        for(int i=0 ; i<n ; i++){
            Numerator = equations[i][0], Denomerator = equations[i][1];
            Val = values[i];
            Graph[Numerator].push_back({Denomerator,Val});
            Graph[Denomerator].push_back({Numerator,1.0/Val});
        }

        vector<double>Result;
        string Start_Node, Target_Node;
        for(auto& q : queries){
            Start_Node=q[0] , Target_Node=q[1];
            if(Graph.find(Start_Node)==Graph.end() || Graph.find(Target_Node)==Graph.end()){
                Result.push_back(-1.0);
                continue;
            }
            queue<pair<string,double>>Q;
            Q.push({Start_Node,1.0});
            unordered_set<string>Visited_Nodes;
            Visited_Nodes.insert(Start_Node);
            bool Reached_Target = false;

            // BFS Workflow

            while(!Q.empty()){
                auto [Curr_Node ,  Curr_Cost] = Q.front();
                Q.pop();

                if(Curr_Node == Target_Node){
                    Result.push_back(Curr_Cost);
                    Reached_Target = true;
                    break;
                }

                for(auto& [Nei , Wei] : Graph[Curr_Node]){
                    if(!Visited_Nodes.count(Nei)){
                        Visited_Nodes.insert(Nei);
                        Q.push({Nei, Curr_Cost*Wei});
                    }
                }

            }  // End Clause for While Loop (BFS_Q)
        
        if(!Reached_Target){
            Result.push_back(-1.0);
        }

        }  // End Clause for For Loop (queries Traverse)
        return Result;
    }
};


/*

// Iterative DFS Approach:  Time Complexity: O(N(Edges  in equation) + Q(Queries) * V(Nodes in Graph)) ;  
//                          Space Complexity: O(N + V)
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>>Graph;
        string Numerator,Denomerator;
        double Val;
        
        //Building the Graph
        for(int i=0 ; i<n ; i++){
            Numerator = equations[i][0], Denomerator = equations[i][1];
            Val = values[i];
            Graph[Numerator].push_back({Denomerator,Val});
            Graph[Denomerator].push_back({Numerator,1.0/Val});
        }

       string Start_Node, Last_Node;
       vector<double>Result;
       for(auto& q : queries){
        string Start_Node=q[0],Last_Node=q[1];
        if(Graph.find(Start_Node)==Graph.end() || Graph.find(Last_Node)==Graph.end()){
            Result.push_back(-1.0);
            continue; // to neglect result of lines and go to the next query
        }
        unordered_set<string>Visited_Nodes;
        stack<pair<string,double>>Stk;
        Stk.push({Start_Node,1.0});
        bool Reached_Last_Node=false;
        
        while(!Stk.empty()){
            auto [Curr_Node , Curr_Cost] = Stk.top();
            Stk.pop();
            

            //Reached Last Node Check
            if(Curr_Node == Last_Node){
                Result.push_back(Curr_Cost);
                Reached_Last_Node = true;
                break; // Exit from While Loop
            }

            Visited_Nodes.insert(Curr_Node);
            for(auto& [Nei,Wei] : Graph[Curr_Node]){
                if(!Visited_Nodes.count(Nei)){
                    Stk.push({Nei,Curr_Cost * Wei});
                }
            }
        } // While Loop Closing Clause

        if(!Reached_Last_Node){
            Result.push_back(-1.0);
        }

       } // For Loop Closing Clause
       return Result;
    }
*/



// Recursive DFS Approach:  Time Complexity: O(N(Edges  in equation) + Q(Queries) * V(Nodes in Graph)) ;  
//                          Space Complexity: O(N + V)
/*
 double DFS_Helper(string Curr_Node, string Target_Node, unordered_map<string,vector<pair<string,double>>>Graph,
                    unordered_set<string>&Visited_Nodes){
                        if(Curr_Node == Target_Node){
                            return 1.0;
                        }
                        Visited_Nodes.insert(Curr_Node);

                        for(auto& [Nei , Wei] : Graph[Curr_Node]){
                            if(!Visited_Nodes.count(Nei)){
                                double Curr_Prod = DFS_Helper(Nei,Target_Node,Graph,Visited_Nodes);
                                if(Curr_Prod!=-1.0) {
                                    return Curr_Prod * Wei;
                                }
                            }
                        }
                        return -1.0;
                    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>>Graph;
        string Numerator,Denomerator;
        double Val;
        
        //Building the Graph
        for(int i=0 ; i<n ; i++){
            Numerator = equations[i][0], Denomerator = equations[i][1];
            Val = values[i];
            Graph[Numerator].push_back({Denomerator,Val});
            Graph[Denomerator].push_back({Numerator,1.0/Val});
        }
        vector<double>Result;
        string Start_Node, Last_Node;
        for(auto& q : queries){
            Start_Node=q[0] , Last_Node=q[1];
            if(Graph.find(Start_Node)==Graph.end() || Graph.find(Start_Node)==Graph.end()){
                Result.push_back(-1.0);
                continue;
            }
            unordered_set<string>Visited_Nodes;
            Result.push_back(DFS_Helper(Start_Node,Last_Node,Graph,Visited_Nodes));
        }
        return Result;
    }
*/