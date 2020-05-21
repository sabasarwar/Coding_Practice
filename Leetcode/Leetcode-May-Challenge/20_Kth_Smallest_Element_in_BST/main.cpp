/* ---------------------- Problem Statement -----------------------
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the 
kth smallest frequently? How would you optimize the kthSmallest routine?
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
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int count = 0;
        int result = 0;
        inorder(root, k, count, result);
        return result;     
    }
    
    void inorder(TreeNode* root, int k, int& count, int& result) 
    {
        if(root->left)
            inorder(root->left, k, count, result);
        count++;
        if(count == k) 
        {
            result = root->val;
            return;
        }
        if(root->right)
            inorder(root->right, k, count, result);
    }
};