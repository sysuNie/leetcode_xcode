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
    // 思路：后序遍历。直径等于左子树最大深度 + 右子树最大深度。递归计算每个节点的深度，同时更新全局直径最大值。
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }

    // 返回当前节点的最大深度，同时更新全局直径
    int depth(TreeNode* node, int& diameter) {
        if (!node) return 0;

        // 左子树深度
        int leftDepth = depth(node->left, diameter);
        // 右子树深度
        int rightDepth = depth(node->right, diameter);

        // 经过当前节点的直径 = 左深度 + 右深度
        diameter = max(diameter, leftDepth + rightDepth);

        // 返回当前节点的最大深度（左右子树深度的较大值 + 1）
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