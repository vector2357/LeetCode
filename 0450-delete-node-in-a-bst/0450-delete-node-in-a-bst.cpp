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
    TreeNode* Max(TreeNode* R) {
        if(!R || !R->right) {
            return R;
        }
        return Max(R->right);
    }

    void Delete(TreeNode** R, int K) {
        if(!(*R)) {
            return;
        }

        if(K < (*R)->val) {
            Delete(&(*R)->left, K);
        }
        else {
            if(K > (*R)->val) {
                return Delete(&(*R)->right, K);
            }
            else {
                if(!(*R)->left) {
                    TreeNode* P = (*R);
                    *R = (*R)->right;
                    delete P;
                    return;
                }
                if(!(*R)->right) {
                    TreeNode* P = (*R);
                    *R = (*R)->left;
                    delete P;
                    return;
                }
                TreeNode* P = Max((*R)->left);
                swap((*R)->val, P->val);
                Delete(&(*R)->left, K);
            }
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        Delete(&root, key);
        return root;
    }
};