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

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;

        for(int i=0; i<preorder.size(); i++) {
            insert(&root, new TreeNode(preorder[i]), preorder[i]);
        }
        return root;
    }
};