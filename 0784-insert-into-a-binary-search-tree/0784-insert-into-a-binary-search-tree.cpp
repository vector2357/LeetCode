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
    void insert(TreeNode** R, TreeNode* P, int K) {
        if(!(*R)) {
            *R = P;
        }
        else {
            if(K < (*R)->val) {
                insert(&(*R)->left, P, K);
            }
            else {
                insert(&(*R)->right, P, K);
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        insert(&root, newNode, val);
        return root;
    }
};