> lowest common ancestor is dependent of the root

> logic being this is that, there are 2 cases , first is that there is a separate node with is lca of both of then , second one of them is lca itself.
- for the first notice , it will be the node with both the required nodes in its separate children . so if we return true if any required node is in the subtree of current node . the node with any 2 children true will be lca.
- for the second case , notice when it will happen , we will get true from one of the child , and current will also be true { as it is required node}.

> SO LCA THE FIRST NODE WITH BOTH THE BOTH THE REQUIRED NODES IN ITS SUBTREE.

```cpp
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
    bool func(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*&ans){
        if(root==NULL){
            return false;
        }
        bool cur=false;
        if(root==p ||root==q){
            cur=true;
        }
        bool l=func(root->left,p,q,ans);
        bool r=func(root->right,p,q,ans);
        if((l&&r) || (l&&cur) || (r&&cur)){
            ans=root;
        }
        return (cur||l||r);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*ans=NULL;
        func(root,p,q,ans);
        return ans;
    }
};

```