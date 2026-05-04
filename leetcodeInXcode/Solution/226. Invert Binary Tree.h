//
//  226. Invert Binary Tree.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _26__Invert_Binary_Tree_h
#define _26__Invert_Binary_Tree_h

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 思路：递归。先交换当前节点的左右子树，再递归翻转左右子树。
    TreeNode* invertTree(TreeNode* root) {
        // 递归终止条件
        if (root == nullptr) return nullptr;

        // 交换左右子树
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 递归翻转左子树
        invertTree(root->left);
        // 递归翻转右子树
        invertTree(root->right);

        return root;
    }

    void inorderPrint(TreeNode* root) {
        if (root == nullptr) return;
        inorderPrint(root->left);
        cout << root->val << " ";
        inorderPrint(root->right);
    }

    void Test()
    {
        TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(7);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(9);

        root = invertTree(root);
        inorderPrint(root);
        cout << endl;
    }
};

#endif /* _26__Invert_Binary_Tree_h */