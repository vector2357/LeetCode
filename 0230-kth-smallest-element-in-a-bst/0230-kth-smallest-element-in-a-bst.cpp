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
    int ans, cont=0;

    void inOrder(TreeNode* R, int k) {
        if(R) {
            inOrder(R->left, k);
            cont++;
            if(cont == k) {
                ans=R->val;
                return;
            }
            inOrder(R->right, k);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};