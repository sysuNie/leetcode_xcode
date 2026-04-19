//
//  tenary.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

class TreeNode {
public:
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {};
};

TreeNode * parse(string s) {
    if (s.length() == 0) return nullptr;
    stack<TreeNode *> st;
    TreeNode *root = new TreeNode(s[0]);
    st.push(root);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '?') {
            TreeNode *left = new TreeNode(s[++i]);
            st.top()->left = left;
            st.push(left);
        } else if (s[i] == ':') {
            TreeNode *right = new TreeNode(s[++i]);
            // pop left sibling
            st.pop();
            // add this node as right child
            st.top()->right = right;
            // pop parent
            st.pop();
            // add self
            st.push(right);
        }
    }
    return root;
}

