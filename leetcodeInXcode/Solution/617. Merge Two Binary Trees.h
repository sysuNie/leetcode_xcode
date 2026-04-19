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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

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