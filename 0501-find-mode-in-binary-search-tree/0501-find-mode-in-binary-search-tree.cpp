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
    map<int, int> mp;
    int maxx=1;

    void search(TreeNode* root) {
        if(root == NULL) return;

        mp[root->val]++;
        maxx = max(maxx, mp[root->val]);

        search(root->left);
        search(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        search(root);
        vector<int> ans;

        for(auto it : mp) {
            if(it.second == maxx) ans.push_back(it.first);
        }

        return ans;
    }
};