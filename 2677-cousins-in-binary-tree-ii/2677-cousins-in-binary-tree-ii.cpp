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
    long long sum[100001] = {0};

    void sumTree(int idx, TreeNode* root) {
        if(root == NULL) return;

        sum[idx] += root->val;

        sumTree(idx+1, root->left);
        sumTree(idx+1, root->right);
    }

    void replace(int idx, TreeNode* root) {
        if(root == NULL) return;

        long long replaceVal = sum[idx+1];

        if(root->left != NULL) replaceVal -= root->left->val;
        if(root->right != NULL) replaceVal -= root->right->val;

        if(root->left != NULL) root->left->val = replaceVal;
        if(root->right != NULL) root->right->val = replaceVal;

        replace(idx+1, root->left);
        replace(idx+1, root->right);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        sumTree(0, root);
        root->val = 0;
        replace(0, root);

        return root;
    }
};