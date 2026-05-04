//
//  105. Construct Binary Tree from Preorder and Inorder Traversal.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _05__Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_h
#define _05__Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_h

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
    // 思路：递归构建。前序首元素为根，在中序中找到根的位置划分左右子树，递归构建左右子树。
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;

        // 前序第一个值为当前根节点
        int rootVal = preorder[preStart];
        int rootIndex = 0;

        // 在中序遍历中找到根节点的位置，划分左右子树
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        // 左子树的节点个数
        int leftSize = rootIndex - inStart;

        TreeNode* root = new TreeNode(rootVal);
        // 前序中左子树区间
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           // 中序中左子树区间
                           inorder, inStart, rootIndex - 1);
        // 前序中右子树区间
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            // 中序中右子树区间
                            inorder, rootIndex + 1, inEnd);

        return root;
    }

    void inorderPrint(TreeNode* root) {
        if (root == nullptr) return;
        inorderPrint(root->left);
        cout << root->val << " ";
        inorderPrint(root->right);
    }

    void Test()
    {
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};

        TreeNode* root = buildTree(preorder, inorder);
        inorderPrint(root);
        cout << endl;
    }
};

#endif /* _05__Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_h */