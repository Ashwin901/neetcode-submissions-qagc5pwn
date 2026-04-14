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

    TreeNode* helper(int l, int r, unordered_map<int, pair<int, int>> &umap, vector<int> &in, vector<int> &pre){
        if(l == r){
            return new TreeNode(in[l]);
        }

        if(l > r) return NULL;

        // check which element between l - r, has the least index in preorder
        int pIdx = INT_MAX, iIdx = -1;
        for(int i = l;i<=r;i++){
            int curr = umap[in[i]].first;
            if(curr < pIdx) {
                pIdx = curr;
                iIdx = i;
            }
        }

        // idx is the root of this subtree
        TreeNode* root = new TreeNode(pre[pIdx]);
        root->left = helper(l,iIdx-1,umap,in,pre);
        root->right = helper(iIdx+1,r,umap,in,pre);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int, pair<int, int>> umap;

        int n = pre.size();

        for(int i = 0;i<n;i++){
            umap[pre[i]].first = i;
            umap[in[i]].second = i;
        }

        return helper(0,n-1,umap,in,pre);
    }
};
