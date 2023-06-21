										Approach 1
#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    //base case
    if(root == NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }
    if(root->data > x){
        //left part me
        return searchInBST(root->left, x);
    }

    else{
        return searchInBST(root->right, x);
    }
}

												Approach 2
#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int>* temp = root;
    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        if(temp->data>x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
}	