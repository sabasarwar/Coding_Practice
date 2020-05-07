/* ---------------------- Problem Statement -----------------------
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
---------------------------------------------------------------------*/

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
class Solution 
{
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
        int d=0;
        int dX=-1; //depth of x
        int dY=-1; //depth of y
        int pX=0; //parent of x
        int pY=0; //parent of y
        parent_depth(root, x, y, d, dX, dY, pX, pY);
        if((dX==dY) && (pX!=pY))
            return true;
        else
            return false;
    }
    
    void parent_depth(TreeNode* root, int x, int y, int d, int& dX, int& dY, int& pX, int& pY)
    {
        if(!root)
            return;
        if(root->left)
        {
            if(root->left->val == x)
            {
                pX=root->val;
                dX=d+1;
            }
            else if(root->left->val == y)
            {
                pY=root->val;
                dY=d+1;
            }
        }
        
        if(root->right)
        {
            if(root->right->val == x)
            {
                pX=root->val;
                dX=d+1;
            }
            else if(root->right->val == y)
            {
                pY=root->val;
                dY=d+1;
            }
        }
        if(dX!=-1 && dY!=-1)
            return;
        parent_depth(root->left, x, y, d+1, dX, dY, pX, pY);
        parent_depth(root->right, x, y, d+1, dX, dY, pX, pY);
        
    }
};