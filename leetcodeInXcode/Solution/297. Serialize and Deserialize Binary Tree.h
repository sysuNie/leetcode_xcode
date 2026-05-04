//
//  297. Serialize and Deserialize Binary Tree.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _97__Serialize_and_Deserialize_Binary_Tree_h
#define _97__Serialize_and_Deserialize_Binary_Tree_h

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // 思路：使用前序遍历（DFS）进行序列化和反序列化。空节点用 "null" 标记，节点值用空格分隔。
    string serialize(TreeNode* root) {
        ostringstream oss;
        // 递归前序遍历序列化
        serializeHelper(root, oss);
        return oss.str();
    }

    void serializeHelper(TreeNode* node, ostringstream& oss) {
        if (!node) {
            // 空节点标记
            oss << "null ";
            return;
        }
        // 输出当前节点值
        oss << node->val << " ";
        // 递归序列化左子树
        serializeHelper(node->left, oss);
        // 递归序列化右子树
        serializeHelper(node->right, oss);
    }

    TreeNode* deserialize(string data) {
        // 将字符串转为输入流
        istringstream iss(data);
        return deserializeHelper(iss);
    }

    TreeNode* deserializeHelper(istringstream& iss) {
        string val;
        // 读取下一个值
        iss >> val;
        // 空节点直接返回
        if (val == "null") return nullptr;

        // 创建当前节点
        TreeNode* node = new TreeNode(stoi(val));
        // 递归构建左子树
        node->left = deserializeHelper(iss);
        // 递归构建右子树
        node->right = deserializeHelper(iss);
        return node;
    }
};

class Solution {
public:
    void Test()
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(5);

        Codec codec;
        string data = codec.serialize(root);
        cout << data << endl;

        TreeNode* newRoot = codec.deserialize(data);
        cout << newRoot->val << " " << newRoot->right->left->val << endl;
    }
};

#endif /* _97__Serialize_and_Deserialize_Binary_Tree_h */