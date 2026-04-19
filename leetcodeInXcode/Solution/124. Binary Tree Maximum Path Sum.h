//
//  124. Binary Tree Maximum Path Sum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _24__Binary_Tree_Maximum_Path_Sum_h
#define _24__Binary_Tree_Maximum_Path_Sum_h

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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

    int maxGain(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;

        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        int pathSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, pathSum);

        return node->val + max(leftGain, rightGain);
    }

    void Test()
    {
        TreeNode* root = new TreeNode(-10);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        cout << maxPathSum(root) << endl;
    }
};

#endif /* _24__Binary_Tree_Maximum_Path_Sum_h */