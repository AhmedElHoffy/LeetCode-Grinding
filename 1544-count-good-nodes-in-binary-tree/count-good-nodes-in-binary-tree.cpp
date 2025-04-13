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
};