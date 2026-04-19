//
//  543. Diameter of Binary Tree.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _43__Diameter_of_Binary_Tree_h
#define _43__Diameter_of_Binary_Tree_h

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }

    int depth(TreeNode* node, int& diameter) {
        if (!node) return 0;

        int leftDepth = depth(node->left, diameter);
        int rightDepth = depth(node->right, diameter);

        diameter = max(diameter, leftDepth + rightDepth);

        return max(leftDepth, rightDepth) + 1;
    }

    void Test()
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);

        cout << diameterOfBinaryTree(root) << endl;
    }
};

#endif /* _43__Diameter_of_Binary_Tree_h */