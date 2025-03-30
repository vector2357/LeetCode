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
    vector<int> v;
    bool ans=true;

    void inOrder(TreeNode* R) {
        if(R) {
            inOrder(R->left);
            if(v.size() && R->val <= v[v.size()-1]) {
                ans=false;
            }
            v.push_back(R->val);
            inOrder(R->right);
        }
    }

    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};