//
//  104. Maximum Depth of Binary Tree.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _04__Maximum_Depth_of_Binary_Tree_h
#define _04__Maximum_Depth_of_Binary_Tree_h

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
    // 思路：BFS层序遍历，每遍历一层深度加1，最后得到最大深度。
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            // 每处理一层，深度加1
            depth++;
            // 当前层节点数
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // 左子节点入队
                if (node->left) q.push(node->left);
                // 右子节点入队
                if (node->right) q.push(node->right);
            }
        }

        return depth;
    }

    void Test()
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        cout << maxDepth(root) << endl;
    }
};

#endif /* _04__Maximum_Depth_of_Binary_Tree_h */