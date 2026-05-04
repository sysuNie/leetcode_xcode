//
//  101. Symmetric Tree.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _01__Symmetric_Tree_h
#define _01__Symmetric_Tree_h

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
    // 思路：递归判断二叉树是否对称，即左子树和右子树互为镜像。
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

    // 判断两棵树是否互为镜像：根值相等，且一棵的左子树与另一棵的右子树镜像
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;

        return (left->val == right->val) &&
               // 外侧子树对比
               isMirror(left->left, right->right) &&
               // 内侧子树对比
               isMirror(left->right, right->left);
    }

    void Test()
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(3);

        cout << (isSymmetric(root) ? "true" : "false") << endl;
    }
};

#endif /* _01__Symmetric_Tree_h */