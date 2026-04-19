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
    string serialize(TreeNode* root) {
        ostringstream oss;
        serializeHelper(root, oss);
        return oss.str();
    }

    void serializeHelper(TreeNode* node, ostringstream& oss) {
        if (!node) {
            oss << "null ";
            return;
        }
        oss << node->val << " ";
        serializeHelper(node->left, oss);
        serializeHelper(node->right, oss);
    }

    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }

    TreeNode* deserializeHelper(istringstream& iss) {
        string val;
        iss >> val;
        if (val == "null") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(iss);
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