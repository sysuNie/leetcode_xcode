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
    // 思路：递归验证BST，每个节点必须在其上下界范围内，左子树更新上界，右子树更新下界。
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

    // minNode/maxNode 分别记录当前节点允许的最小/最大值边界
    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (node == nullptr) return true;

        // 违反下界约束
        if (minNode != nullptr && node->val <= minNode->val) return false;
        // 违反上界约束
        if (maxNode != nullptr && node->val >= maxNode->val) return false;

        // 左子树的上界变为当前节点值
        return validate(node->left, minNode, node) &&
               // 右子树的下界变为当前节点值
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