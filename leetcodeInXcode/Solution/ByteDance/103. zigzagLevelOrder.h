//
//  103. zigzagLevelOrder.h
//  leetcodeInXcode
//
//  Created by niejikang on 24.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _03__zigzagLevelOrder_h
#define _03__zigzagLevelOrder_h

/**
 103. 二叉树的锯齿形层次
 236. 二叉树的最近公共祖先
 102. 二叉树额度层序遍历
 113. 路径总和
 101. 对称二叉树
 199. 二叉树的右视图
 143. 树的子结构
 */

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (!root) {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            res.push_back(level);
            leftToRight = !leftToRight;
        }
        
        return res;
    }
};

#endif /* _03__zigzagLevelOrder_h */
