//
//  98. Validate Binary Search Tree.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _8__Validate_Binary_Search_Tree_h
#define _8__Validate_Binary_Search_Tree_h

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
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (node == nullptr) return true;

        if (minNode != nullptr && node->val <= minNode->val) return false;
        if (maxNode != nullptr && node->val >= maxNode->val) return false;

        return validate(node->left, minNode, node) &&
               validate(node->right, node, maxNode);
    }

    void Test()
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(3);

        cout << (isValidBST(root) ? "true" : "false") << endl;
    }
};

#endif /* _8__Validate_Binary_Search_Tree_h */