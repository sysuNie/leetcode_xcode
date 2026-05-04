//
//  337. House Robber III.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _37__House_Robber_III_h
#define _37__House_Robber_III_h

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 思路：树形动态规划。每个节点返回一个 pair，first 表示不抢该节点的最大收益，second 表示抢该节点的最大收益。后序遍历，根据子节点结果计算父节点。
    int rob(TreeNode* root) {
        auto result = robHelper(root);
        // 根节点抢或不抢的最大值
        return max(result.first, result.second);
    }

    // 返回 pair：first 为不抢当前节点的最大收益，second 为抢当前节点的最大收益
    pair<int, int> robHelper(TreeNode* node) {
        // 空节点收益为 0
        if (!node) return {0, 0};

        // 递归计算左子树
        auto left = robHelper(node->left);
        // 递归计算右子树
        auto right = robHelper(node->right);

        // 不抢当前节点：子节点可抢可不抢，取各自最大值
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        // 抢当前节点：子节点一定不能抢
        int rob = node->val + left.first + right.first;

        return {notRob, rob};
    }

    void Test()
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(1);

        cout << rob(root) << endl;
    }
};

#endif /* _37__House_Robber_III_h */