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
    int rob(TreeNode* root) {
        auto result = robHelper(root);
        return max(result.first, result.second);
    }

    pair<int, int> robHelper(TreeNode* node) {
        if (!node) return {0, 0};

        auto left = robHelper(node->left);
        auto right = robHelper(node->right);

        int notRob = max(left.first, left.second) + max(right.first, right.second);
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