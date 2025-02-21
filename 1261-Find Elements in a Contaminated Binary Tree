class FindElements {
    unordered_set<int> node_values;
    void recoverBinaryTree(TreeNode* curr,int val){
        if(!curr)   return;

        node_values.insert(val);
        recoverBinaryTree(curr->left,2*val+1);
        recoverBinaryTree(curr->right,2*val+2);
    }
public:
    FindElements(TreeNode* root) {
        node_values.insert(0);
        recoverBinaryTree(root->left,1);
        recoverBinaryTree(root->right,2);
    }
    
    bool find(int target) {
        return node_values.count(target)>0;
    }
};
