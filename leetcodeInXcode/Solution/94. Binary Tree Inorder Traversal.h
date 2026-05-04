//
//  94. Binary Tree Inorder Traversal.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _4__Binary_Tree_Inorder_Traversal_h
#define _4__Binary_Tree_Inorder_Traversal_h

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
    // 思路：迭代实现中序遍历，利用栈模拟递归过程。先一路向左将节点压栈，到底后弹出访问，再转向右子树。
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()) {
            // 将当前节点及其所有左子节点依次压栈
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            // 弹出栈顶节点访问，并转向其右子树
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }

        return result;
    }

    void Test()
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);

        vector<int> result = inorderTraversal(root);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
};

#endif /* _4__Binary_Tree_Inorder_Traversal_h */