TreeNode* buildTreeHelper(vector<int> &preorder, int startPre, int endPre, vector<int> &inorder, int startIn, int endIn, unordered_map<int, int> &inMap){

        if(startIn > endIn || startPre > endPre) return NULL;

        TreeNode* curr = new TreeNode(preorder[startPre]);

        int currNodeIndex = inMap[preorder[startPre]];
        int totalElemInLeft = currNodeIndex - startIn;


        curr->left = buildTreeHelper(preorder, startPre+1, startPre+totalElemInLeft, inorder, startIn, currNodeIndex-1, inMap);
        curr->right = buildTreeHelper(preorder, startPre+totalElemInLeft+1, endPre, inorder, currNodeIndex+1, endIn, inMap);

        return curr;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;

        for(int i=0 ;i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }