//
//  offer 26. isSubStructure.h
//  leetcodeInXcode
//
//  Created by niejikang on 24.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef offer_26__isSubStructure_h
#define offer_26__isSubStructure_h

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool match(TreeNode* A, TreeNode* B)
    {
        if (!A) return true;
        if (!B) return true;
        
        if (A->val != B->val) {
            return false;
        }
        
        return match(A->left, B->left) && match(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) {
            return false;
        }
        
        return match(A, B)
            || isSubStructure(A->left, B)
            || isSubStructure(A->right, B);
    }
};

#endif /* offer_26__isSubStructure_h */
