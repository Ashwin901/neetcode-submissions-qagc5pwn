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

class Codec {
public:

    int preIdx = 0;
 
    void preorder(TreeNode* root, string &res){
        if(!root) {
            res += "#, ";
            return;
        }

        res = res + to_string(root->val);
        res = res + ",";
        preorder(root->left,res);
        preorder(root->right,res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        preorder(root,res);
        return res;
    }

    TreeNode* helper(vector<string> &nodes){
        if(preIdx >= nodes.size() || nodes[preIdx] == "#") {
            preIdx++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(nodes[preIdx++]));
        node->left = helper(nodes);
        node->right = helper(nodes);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        vector<string> nodes;
        stringstream ss(data);
        string t;
        while(getline(ss, t, ',')){
            // Trim potential leading space from the delimiter
            if(!t.empty() && t[0] == ' ') t.erase(0, 1);
            if(!t.empty()) nodes.push_back(t);
        }

        preIdx = 0;
        return helper(nodes);
    }
};