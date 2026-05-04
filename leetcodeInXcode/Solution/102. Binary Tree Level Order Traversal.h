//
//  102. Binary Tree Level Order Traversal.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _02__Binary_Tree_Level_Order_Traversal_h
#define _02__Binary_Tree_Level_Order_Traversal_h

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
    // 思路：BFS层序遍历，利用队列逐层处理节点，每轮记录当前层的节点数量。
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // 当前层的节点数
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                // 左子节点入队
                if (node->left) q.push(node->left);
                // 右子节点入队
                if (node->right) q.push(node->right);
            }

            // 将当前层结果加入答案
            result.push_back(level);
        }

        return result;
    }

    void Test()
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        vector<vector<int>> result = levelOrder(root);
        for (const auto& level : result) {
            for (int val : level) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

#endif /* _02__Binary_Tree_Level_Order_Traversal_h */