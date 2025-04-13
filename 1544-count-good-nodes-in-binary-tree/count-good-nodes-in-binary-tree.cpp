/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int DFS_Helper (TreeNode* Curr_Node, int Max_SoFar){
        if(!Curr_Node) return 0;
        int Count = (Curr_Node->val >= Max_SoFar) ? 1:0;
        Max_SoFar = max(Max_SoFar,Curr_Node->val);
        return Count + DFS_Helper(Curr_Node->left,Max_SoFar) + DFS_Helper(Curr_Node->right,Max_SoFar);
    }
    int goodNodes(TreeNode* root) {
        int Count=0;
        return DFS_Helper(root,root->val);
    }
};




// Iterative DFS ;  Time: O(N) and Space:O(H)
/*
int goodNodes(TreeNode* root) {
        int Count=0;
        if(!root) return Count;

        stack<pair<TreeNode*,int>>Stk;
        Stk.push({root,root->val});
        TreeNode* Curr_Node;
        int New_Max_Node;
        while(!Stk.empty()){
            auto [Curr_Node, Max_So_Far] = Stk.top();
            Stk.pop();
            if(Curr_Node->val >= Max_So_Far){
                Count++;
            }
            New_Max_Node = max(Max_So_Far,Curr_Node->val);
            
            if(Curr_Node->left) Stk.push({Curr_Node->left,New_Max_Node});
            if(Curr_Node->right) Stk.push({Curr_Node->right,New_Max_Node});
        }
        return Count;
    }
*/