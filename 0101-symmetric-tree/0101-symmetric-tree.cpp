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
    bool verify(TreeNode* l, TreeNode* r) {
        if(l==NULL && r==NULL) return true;
        if(l==NULL || r==NULL || l->val != r->val) return false;

        return verify(l->left, r->right) && verify(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return verify(root->left, root->right);
    }
};