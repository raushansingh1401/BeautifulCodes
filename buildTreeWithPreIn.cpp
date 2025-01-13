class Solution {
public:
    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inMap, int startInd, int endInd, int &preInd){
        if(startInd > endInd) return NULL;
            
        TreeNode* newCreatedNode = new TreeNode(preorder[preInd]);
        int createdNodeInd = inMap[preorder[preInd]];
        preInd++;
            
        newCreatedNode->left = buildTreeHelper(preorder, inorder, inMap, startInd, createdNodeInd - 1, preInd);
        newCreatedNode->right = buildTreeHelper(preorder, inorder, inMap, createdNodeInd + 1, endInd, preInd);
        return newCreatedNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        int startInd(0), endInd(preorder.size() - 1), preInd(0);
        return buildTreeHelper(preorder, inorder, inMap, startInd, endInd, preInd);
    }
};
