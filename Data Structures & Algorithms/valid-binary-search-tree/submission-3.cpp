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

    bool helper(TreeNode* node, int left, int right){
        if(!node) return true;
        if(node->val <= left || node->val >= right) return false;

        return helper(node->left, left, node->val) && helper(node->right, node->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};
