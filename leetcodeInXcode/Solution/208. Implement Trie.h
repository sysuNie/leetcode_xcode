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

    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Node();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) {
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