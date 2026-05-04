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
    // 思路：递归后序遍历，计算每个节点的最大贡献值，同时更新全局最大路径和。
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

    // 返回以当前节点为端点的最大路径贡献值（只能选一侧子树）
    int maxGain(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;

        // 左子树贡献值，负值则取0（不选）
        int leftGain = max(maxGain(node->left, maxSum), 0);
        // 右子树贡献值，负值则取0（不选）
        int rightGain = max(maxGain(node->right, maxSum), 0);

        // 以当前节点为拐点的路径和（左+根+右）
        int pathSum = node->val + leftGain + rightGain;
        // 更新全局最大路径和
        maxSum = max(maxSum, pathSum);

        // 返回以当前节点为端点的最大贡献值（只能走一侧）
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