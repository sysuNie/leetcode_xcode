//
//  617. Merge Two Binary Trees.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _17__Merge_Two_Binary_Trees_h
#define _17__Merge_Two_Binary_Trees_h

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 思路：递归合并。如果其中一个节点为空，返回另一个节点；否则将 t2 的值加到 t1 上，然后递归合并左右子树。
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // t1 为空，直接返回 t2
        if (!t1) return t2;
        // t2 为空，直接返回 t1
        if (!t2) return t1;

        // 合并当前节点的值
        t1->val += t2->val;
        // 递归合并左子树
        t1->left = mergeTrees(t1->left, t2->left);
        // 递归合并右子树
        t1->right = mergeTrees(t1->right, t2->right);

        // 返回合并后的根节点
        return t1;
    }

    void inorderPrint(TreeNode* root) {
        if (!root) return;
        inorderPrint(root->left);
        cout << root->val << " ";
        inorderPrint(root->right);
    }

    void Test()
    {
        TreeNode* t1 = new TreeNode(1);
        t1->left = new TreeNode(3);
        t1->right = new TreeNode(2);
        t1->left->left = new TreeNode(5);

        TreeNode* t2 = new TreeNode(2);
        t2->left = new TreeNode(1);
        t2->right = new TreeNode(3);
        t2->left->right = new TreeNode(4);
        t2->right->right = new TreeNode(7);

        TreeNode* result = mergeTrees(t1, t2);
        inorderPrint(result);
        cout << endl;
    }
};

#endif /* _17__Merge_Two_Binary_Trees_h */