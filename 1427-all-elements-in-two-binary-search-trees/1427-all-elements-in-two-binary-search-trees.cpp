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
    vector<int> v1, v2;

    void inOrder(TreeNode* R, vector<int>& v) {
        if(R) {
            inOrder(R->left, v);
            v.push_back(R->val);
            inOrder(R->right, v);
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        inOrder(root1, v1);
        inOrder(root2, v2);

        int i, j;
        for(i=0, j=0; i<v1.size() && j<v2.size();) {
            if(v1[i] <= v2[j]) {
                ans.push_back(v1[i]);
                i++;
            }
            else {
                ans.push_back(v2[j]);
                j++;
            }
        }
        for(; i<v1.size(); i++) ans.push_back(v1[i]);
        for(; j<v2.size(); j++) ans.push_back(v2[j]);

        return ans;
    }
};