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
    int ans = 100001, ant = 100001;

    void inOrder(TreeNode* R) {
        if(R) {
            inOrder(R->left);
            ans = min(ans, abs(R->val - ant));
            ant = R->val;
            inOrder(R->right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};