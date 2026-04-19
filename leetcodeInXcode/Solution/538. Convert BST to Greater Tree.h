//
//  538. Convert BST to Greater Tree.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _38__Convert_BST_to_Greater_Tree_h
#define _38__Convert_BST_to_Greater_Tree_h

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertHelper(root, sum);
        return root;
    }

    void convertHelper(TreeNode* node, int& sum) {
        if (!node) return;

        convertHelper(node->right, sum);
        sum += node->val;
        node->val = sum;
        convertHelper(node->left, sum);
    }

    void inorderPrint(TreeNode* root) {
        if (!root) return;
        inorderPrint(root->left);
        cout << root->val << " ";
        inorderPrint(root->right);
    }

    void Test()
    {
        TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(1);
        root->right = new TreeNode(6);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(2);
        root->right->left = new TreeNode(5);
        root->right->right = new TreeNode(7);
        root->right->right->right = new TreeNode(8);

        convertBST(root);
        inorderPrint(root);
        cout << endl;
    }
};

#endif /* _38__Convert_BST_to_Greater_Tree_h */