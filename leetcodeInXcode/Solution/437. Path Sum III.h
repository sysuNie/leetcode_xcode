//
//  437. Path Sum III.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _37__Path_Sum_III_h
#define _37__Path_Sum_III_h

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return pathSumFrom(root, targetSum) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }

    int pathSumFrom(TreeNode* node, long target) {
        if (!node) return 0;
        int count = 0;
        if (node->val == target) count++;
        count += pathSumFrom(node->left, target - node->val);
        count += pathSumFrom(node->right, target - node->val);
        return count;
    }

    void Test()
    {
        TreeNode* root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->right = new TreeNode(-3);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(2);
        root->right->right = new TreeNode(11);
        root->left->left->left = new TreeNode(3);
        root->left->left->right = new TreeNode(-2);
        root->left->right->right = new TreeNode(1);

        cout << pathSum(root, 8) << endl;
    }
};

#endif /* _37__Path_Sum_III_h */