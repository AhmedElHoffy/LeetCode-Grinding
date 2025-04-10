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
    
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int Left_Depth=maxDepth(root->left);
        int Right_Depth=maxDepth(root->right);

        return max(Left_Depth,Right_Depth) + 1;
    }
};



/*
 stack<pair<TreeNode*,int>>Stk;
        int Height=1;
        if(!root) return 0;

        Stk.push({root,Height});
        int Max_Depth=0;
        while(!Stk.empty()){
            auto [Curr_Node,Curr_Depth] = Stk.top();
            Stk.pop();
            
            Max_Depth = max(Max_Depth,Curr_Depth);

            if(Curr_Node->left) Stk.push({Curr_Node->left,Curr_Depth+1});
            if(Curr_Node->right) Stk.push({Curr_Node->right,Curr_Depth+1});
        }
        return Max_Depth;
    }
*/