//
//  236. Lowest Common Ancestor of a Binary Tree.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _36__Lowest_Common_Ancestor_of_a_Binary_Tree_h
#define _36__Lowest_Common_Ancestor_of_a_Binary_Tree_h

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
    // 思路：递归。若当前节点为空或是p/q之一，直接返回。递归搜索左右子树：
    // 若左右子树各找到一个目标节点，则当前节点为最近公共祖先；否则返回非空的一侧。
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 终止条件或找到目标
        if (!root || root == p || root == q) return root;

        // 左子树搜索
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // 右子树搜索
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 左右各找到一个，当前为LCA
        if (left && right) return root;
        // 返回非空的一侧（可能包含两个目标）
        return left ? left : right;
    }

    void Test()
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);

        TreeNode* p = root->left;
        TreeNode* q = root->right;

        TreeNode* result = lowestCommonAncestor(root, p, q);
        cout << result->val << endl;
    }
};

#endif /* _36__Lowest_Common_Ancestor_of_a_Binary_Tree_h */