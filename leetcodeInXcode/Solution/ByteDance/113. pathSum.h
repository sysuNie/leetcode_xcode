//
//  113. pathSum.h
//  leetcodeInXcode
//
//  Created by niejikang on 24.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _13__pathSum_h
#define _13__pathSum_h

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
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& path)
    {
        if (!root) {
            return;
        }
        
        path.push_back(root->val);
        targetSum -= root->val;
        
        if (!root->left && !root->right && targetSum == 0) {
            res.push_back(path);
        }
        dfs(root->left, targetSum, res, path);
        dfs(root->right, targetSum, res, path);
        
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        
        dfs(root, targetSum, res, path);
        
        return res;
    }
};


#endif /* _13__pathSum_h */
