//
//  114. Flatten Binary Tree to Linked List.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _14__Flatten_Binary_Tree_to_Linked_List_h
#define _14__Flatten_Binary_Tree_to_Linked_List_h

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
    // 思路：Morris遍历思想。对于每个有左子树的节点，找到左子树的最右节点，将其右指针接到当前节点的右子树，然后将左子树移到右边。
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // 找到左子树的最右节点（当前节点在中序遍历中的前驱）
                TreeNode* predecessor = curr->left;
                while (predecessor->right) {
                    predecessor = predecessor->right;
                }
                // 将原右子树接到最右节点下方
                predecessor->right = curr->right;
                // 左子树移到右边
                curr->right = curr->left;
                // 清空左指针
                curr->left = nullptr;
            }
            // 继续处理下一个节点
            curr = curr->right;
        }
    }

    void inorderPrint(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->right;
        }
        cout << endl;
    }

    void Test()
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->right = new TreeNode(6);

        flatten(root);
        inorderPrint(root);
    }
};

#endif /* _14__Flatten_Binary_Tree_to_Linked_List_h */