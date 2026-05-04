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
    // 思路：反向中序遍历（右-根-左）。维护一个累加和 sum，先遍历右子树再处理当前节点，确保每个节点的值加上所有大于它的节点值。
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertHelper(root, sum);
        return root;
    }

    // 反向中序遍历：右子树 -> 当前节点 -> 左子树
    void convertHelper(TreeNode* node, int& sum) {
        if (!node) return;

        // 先遍历右子树（值更大的节点）
        convertHelper(node->right, sum);
        // 累加当前节点的原始值
        sum += node->val;
        // 当前节点更新为累加和
        node->val = sum;
        // 再遍历左子树（值更小的节点）
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