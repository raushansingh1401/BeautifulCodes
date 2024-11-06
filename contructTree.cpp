	TreeNode* buildTreeHelper(vector<int> &preorder, int &preInd, vector<int> &inorder, int startIn, int endIn, unordered_map<int, int> &inMap){

        if(startIn > endIn || preInd >= preorder.size()) return NULL;

        int currNodeVal = preorder[preInd];
        preInd++;

        TreeNode* curr = new TreeNode(currNodeVal);

        int currNodeIndex = inMap[currNodeVal];
        int totalElemInLeft = currNodeIndex - startIn;


        curr->left = buildTreeHelper(preorder, preInd, inorder, startIn, currNodeIndex-1, inMap);
        curr->right = buildTreeHelper(preorder, preInd, inorder, currNodeIndex+1, endIn, inMap);

        return curr;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> inMap;

        for(int i=0 ;i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        int preInd = 0;
        return buildTreeHelper(preorder, preInd, inorder, 0, inorder.size()-1, inMap);

    }