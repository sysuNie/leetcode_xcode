//
//  79. Word Search.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _9__Word_Search_h
#define _9__Word_Search_h

class Solution {
public:
    // 思路：回溯 + DFS。遍历棋盘每个格子作为起点，进行深度优先搜索匹配单词。
    // 为防止重复使用同一格子，临时将访问过的格子标记为 '#'，回溯时恢复。
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 从 (i,j) 开始搜索
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        // 越界或字符不匹配，搜索失败
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[idx]) {
            return false;
        }

        // 已匹配到单词最后一个字符
        if (idx == word.length() - 1) {
            return true;
        }

        char temp = board[i][j];
        // 标记已访问，防止重复使用
        board[i][j] = '#';

        // 下
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     // 上
                     dfs(board, word, i - 1, j, idx + 1) ||
                     // 右
                     dfs(board, word, i, j + 1, idx + 1) ||
                     // 左
                     dfs(board, word, i, j - 1, idx + 1);

        // 回溯，恢复格子原字符
        board[i][j] = temp;
        return found;
    }

    void Test()
    {
        vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        string word = "ABCCED";
        cout << (exist(board, word) ? "true" : "false") << endl;
    }
};

#endif /* _9__Word_Search_h */