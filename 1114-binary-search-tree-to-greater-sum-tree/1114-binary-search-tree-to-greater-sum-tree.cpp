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
    int sum=0;
    void greater(TreeNode* R) {
        if(R) {
            greater(R->right);
            R->val = R->val + sum;
            sum = R->val;
            greater(R->left);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        greater(root);
        return root;
    }
};