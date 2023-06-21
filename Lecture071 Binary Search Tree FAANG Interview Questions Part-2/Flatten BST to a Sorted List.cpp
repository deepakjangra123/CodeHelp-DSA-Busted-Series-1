#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>inorderVal;
    //store inorder->sorted values
    inorder(root, inorderVal);
    int n = inorderVal.size();

    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);

    TreeNode<int>* curr = newRoot;

    //2nd Step
    for(int i = 1; i<n; i++){
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    //3rd Step
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}
