/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*,Node*>HashMap;
        queue<Node*>BFS_Q;

        Node* NewGraph = new Node(node->val);
        HashMap[node] = NewGraph;

        BFS_Q.push(node);

        Node* Curr_Node;

        while(!BFS_Q.empty()){
            Curr_Node = BFS_Q.front();
            BFS_Q.pop();

            for(Node* neighbor : Curr_Node->neighbors){
                if(HashMap.find(neighbor)==HashMap.end()){
                   Node* NewCopy = new Node(neighbor->val);
                    HashMap[neighbor] = NewCopy;
                    BFS_Q.push(neighbor); 
                }
              HashMap[Curr_Node]->neighbors.push_back(HashMap[neighbor]);
            }
        }
        return NewGraph;
        
    }
};






/*
Time and Space Complexity Analysis of the DFS Approach
Time Complexity: \U0001d442(\U0001d441+\U0001d438)

Explanation:
    1. Each node in the graph is visited once.
    2. For each node, we traverse through its neighbors, meaning that every edge in the graph is     
       processed once.

    3. Hence, the total time complexity is proportional to the number of nodes  \U0001d441
    and edges  E in the graph.

    Conclusion: The time complexity is \U0001d442(\U0001d441+\U0001d438 )

    O(N+E), where:\U0001d441 is the number of nodes. E is the number of edges.

    Space Complexity: \U0001d442(\U0001d441)

    Explanation:

    The recursion stack for the DFS traversal can go as deep as the number of nodes in the worst case 
        (for example, in a linear graph).

    The hash map (unordered_map<Node*, Node*> Old_to_New_HashMap) stores a mapping for each node, requiring \U0001d442(\U0001d441)
O(N) space to store all the cloned nodes.




/*
class Solution {
    unordered_map<Node*,Node*>Old_to_New_HashMap;
    Node* Clone_DFS(Node* node){
        if(Old_to_New_HashMap.find(node)!=Old_to_New_HashMap.end()){
            return Old_to_New_HashMap[node];
        }
        Node* Copy = new Node(node->val);
        Old_to_New_HashMap[node] = Copy;
        for(auto Nei : node->neighbors){
            Copy->neighbors.push_back(Clone_DFS(Nei));
        }
        return Copy;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        return Clone_DFS(node);
        
    }
};
*/