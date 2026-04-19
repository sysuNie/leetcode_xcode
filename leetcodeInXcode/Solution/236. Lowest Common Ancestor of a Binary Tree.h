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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
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