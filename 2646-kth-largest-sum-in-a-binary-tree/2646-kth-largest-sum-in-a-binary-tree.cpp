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
    long long vet[100001]={0};
    int sz=0;

    void search(int idx, TreeNode* root) {
        if(root == NULL) return;

        vet[idx]+=root->val;
        sz = max(sz, idx);
        search(idx+1, root->left);
        search(idx+1, root->right);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        search(0, root);
        sort(vet, vet+sz+1, greater());
        
        return (sz+1 < k) ? -1 : vet[k-1];
    }
};