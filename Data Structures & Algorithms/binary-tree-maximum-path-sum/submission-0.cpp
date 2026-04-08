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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int val = helper(root);
        return res;
    }

    int helper(TreeNode* root){
        if(!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);

        int nodeSum = l + r < 0 ? root->val : l+r+root->val;
        int maxChildSum = max(l,r) < 0 ? root->val : max(l,r) + root->val;

        res = max(res, max(nodeSum,maxChildSum));
        
        return maxChildSum;
    }
};
