class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        // travarsing right-left-root, storing last accessed root in prev, making current's right as prev and its left as null.
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
        return;

    }
};