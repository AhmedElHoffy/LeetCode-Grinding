/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*>Parent_Map;
        unordered_set<TreeNode*>Ancestors_Set;
        stack<TreeNode*>DFS_Stk;
        
        Parent_Map[root]=nullptr;
        DFS_Stk.push(root);
        
        TreeNode* Curr_Node;
        while(Parent_Map.find(p)==Parent_Map.end() || Parent_Map.find(q)==Parent_Map.end()){
            Curr_Node=DFS_Stk.top();
            DFS_Stk.pop();

            if(Curr_Node->left){
                Parent_Map[Curr_Node->left]=Curr_Node;
                DFS_Stk.push(Curr_Node->left);
            }

            if(Curr_Node->right){
                Parent_Map[Curr_Node->right]=Curr_Node;
                DFS_Stk.push(Curr_Node->right);
            }
        }

        while(p){
            Ancestors_Set.insert(p);
            p = Parent_Map[p];
        }

        while(Ancestors_Set.find(q)==Ancestors_Set.end()){
            q = Parent_Map[q];
        }
        return q;
    }
};

















/*

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return null ptr if neither p or q are not found  or return Curr_Node if either was found
        TreeNode* Curr_Node = root;
        if (Curr_Node == nullptr){
            return nullptr;
        }
        
        if( Curr_Node==p || Curr_Node==q){
            return Curr_Node;
        }
        // DFS on both sides of the tree Left Side and Right side respectively (In a recursive approach)
        TreeNode* LeftChild = lowestCommonAncestor(Curr_Node->left,p,q);
        TreeNode* RightChild = lowestCommonAncestor(Curr_Node->right,p,q);

        // If both Traversal returns Nodes; therefore, the Curr_Node is the LCA for p and q
        if(LeftChild && RightChild){
            return Curr_Node;
        }else if(LeftChild){          
        // Otherwise return the non-null Recursive approach  
        //return the non-null child (either LeftChild or RightChild)
            return LeftChild;
        }else {
            return RightChild;
        }
    }
*/


/*

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

       // Base Case
        if (!root || root == p || root == q) {
            return root;
        }

        // Recursive calls for left and right subtrees
        TreeNode* LeftChild = lowestCommonAncestor(root->left, p, q);
        TreeNode* RightChild = lowestCommonAncestor(root->right, p, q);

        // If both left and right return non-null, root is the LCA
        if (LeftChild && RightChild) {
            return root;
        }

        // Otherwise, return the non-null child (either LeftChild or RightChild)
        return LeftChild ? LeftChild : RightChild;
        
    }
};
*/