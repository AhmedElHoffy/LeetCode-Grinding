/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
       Node* a = p, *b = q;
       while(a!=b){
        a= (a) ? a->parent:q;
        b= (b) ? b->parent:p;
       }
       return a;
    }
};


















/*
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<int>Ancestors_set;
        Node* Temp=p;
        while(Temp){
            Ancestors_set.insert(Temp->val);
            Temp=Temp->parent;
        }
        Temp=q;

        while(Temp){
            if(Ancestors_set.find(Temp->val)!=Ancestors_set.end()){
                return Temp;
            }
            Temp=Temp->parent;
        }
        return nullptr;
    }
*/



/*
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*>Path_P;
        Node* Curr_Node=p;

        //Storing the path of Node p
        while(Curr_Node){
            Path_P.insert(Curr_Node);
            Curr_Node = Curr_Node->parent;
        }
        // If q is an ancestor to p ; therefore the LCA for p and q is q
        if(Path_P.find(q)!=Path_P.end()){
            return q;
        }

        Node* Curr_Node2=q;

        while(Curr_Node2){
            if(Path_P.find(Curr_Node2)!=Path_P.end()){
                return Curr_Node2;
            }
            Curr_Node2 = Curr_Node2->parent;
        }
        return nullptr;
    }
*/





//class Solution {
//public:
  //  Node* lowestCommonAncestor(Node* p, Node * q) {
    
    // Approach 1: Using set to track Parents and find LCA

    /*
    unordered_set<Node*> ancestors;

    // Traverse upwards from `p` and store all its ancestors in the set
        while (p != nullptr) {
            ancestors.insert(p);
            p = p->parent;
        }

        // Traverse upwards from `q` and find the first common ancestor
        while (q != nullptr) {
            if (ancestors.find(q) != ancestors.end()) {
                return q; // Found the LCA
            }
            q = q->parent;
        }
        
        return nullptr; // If no LCA is found (should not happen in a valid tree)
        */

/*
        // Approach 2:  using while loop and keep looping untill match is found, 
      Node* a = p;
        Node* b = q;

        // Traverse upwards until both pointers meet
        while (a != b) {
            // If a reaches the root, reset it to q
            a = (a) ?  a->parent : q;

            // If b reaches the root, reset it to p
            b = (b) ?  b->parent : p;
        }

        // When they meet, return the LCA
        return a;
    }
};

*/