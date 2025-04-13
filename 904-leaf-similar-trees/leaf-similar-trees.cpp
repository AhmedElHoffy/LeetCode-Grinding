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
    int GetNextLeaf(stack<TreeNode*> &Stk){
        TreeNode* Curr_Node;
        while(!Stk.empty()){
            Curr_Node = Stk.top();
            Stk.pop();

            if(Curr_Node->left) Stk.push(Curr_Node->left);
            if(Curr_Node->right) Stk.push(Curr_Node->right);
            if(!Curr_Node->left && !Curr_Node->right) return Curr_Node->val;
        }
        return -1;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>Stk1,Stk2;
        Stk1.push(root1),Stk2.push(root2);
        int Leaf1,Leaf2;
        while(!Stk1.empty() && !Stk2.empty()){
            Leaf1 = GetNextLeaf(Stk1);
            Leaf2 = GetNextLeaf(Stk2);
            if(Leaf1!=Leaf2) return false;
        }
        return Stk1.empty() && Stk2.empty();
    }
};



/*
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>Stk_Tree1;
        stack<TreeNode*>Stk_Tree2;

        Stk_Tree1.push(root1), Stk_Tree2.push(root2);
        vector<int>Leaves_Tree1,Leaves_Tree2;
        TreeNode* Curr_Node;
        while(!Stk_Tree1.empty()){
            Curr_Node = Stk_Tree1.top();
            Stk_Tree1.pop();
            if(!Curr_Node->left && !Curr_Node->right){
                Leaves_Tree1.push_back(Curr_Node->val);
            }
            if(Curr_Node->left) Stk_Tree1.push(Curr_Node->left);
            if(Curr_Node->right) Stk_Tree1.push(Curr_Node->right);
        }

        while(!Stk_Tree2.empty()){
            Curr_Node = Stk_Tree2.top();
            Stk_Tree2.pop();
            if(!Curr_Node->left && !Curr_Node->right){
                Leaves_Tree2.push_back(Curr_Node->val);
            }
            if(Curr_Node->left) Stk_Tree2.push(Curr_Node->left);
            if(Curr_Node->right) Stk_Tree2.push(Curr_Node->right);
        }
        
        cout<<"Leaves_Tree1 = [ ";
        for(int x : Leaves_Tree1){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;

        cout<<"Leaves_Tree2 = [ ";
        for(int x : Leaves_Tree2){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
        return ( (Leaves_Tree1 == Leaves_Tree2) ? true:false);
    }
*/