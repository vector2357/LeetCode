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

    void inOrder(TreeNode* R) {
        if(R) {
            inOrder(R->left);
            v.push_back(R->val);
            inOrder(R->right);
        }
    }

    int minDiffInBST(TreeNode* root) {
        int ans = 100001;
        inOrder(root);

        for(int i=1; i<v.size(); i++) {
            ans = min(ans, v[i]-v[i-1]);
        }
        return ans;
    }
};