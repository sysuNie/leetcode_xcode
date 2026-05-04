//
//  208. Implement Trie.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _08__Implement_Trie_h
#define _08__Implement_Trie_h

class Trie {
private:
    struct Node {
        Node* children[26];
        bool isEnd;
        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // 思路：从根节点逐字符遍历，路径不存在则创建新节点，结尾标记isEnd。
    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            // 计算字符索引（0-25）
            int idx = c - 'a';
            if (!node->children[idx]) {
                // 路径不存在则创建
                node->children[idx] = new Node();
            }
            // 移动到子节点
            node = node->children[idx];
        }
        // 标记单词结尾
        node->isEnd = true;
    }

    // 思路：逐字符匹配，若某字符无对应子节点则单词不存在，最后检查isEnd。
    bool search(string word) {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                // 路径断裂，单词不存在
                return false;
            }
            node = node->children[idx];
        }
        // 必须匹配到完整单词结尾
        return node->isEnd;
    }

    // 思路：与search类似，但只需前缀匹配，不需要检查isEnd。
    bool startsWith(string prefix) {
        Node* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                // 前缀路径不存在
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

class Solution {
public:
    void Test()
    {
        Trie* obj = new Trie();
        obj->insert("apple");
        cout << obj->search("apple") << endl;
        cout << obj->search("app") << endl;
        cout << obj->startsWith("app") << endl;
    }
};

#endif /* _08__Implement_Trie_h */