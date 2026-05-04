//
//  200. Number of Islands.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _00__Number_of_Islands_h
#define _00__Number_of_Islands_h

class Solution {
public:
    // 思路：遍历网格，遇到'1'则启动DFS/BFS将相连的'1'全部标记为'0'（淹没岛屿），计数+1。
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 发现新岛屿
                if (grid[i][j] == '1') {
                    // 淹没整个岛屿
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

    // 思路：深度优先搜索，将当前陆地及相邻陆地全部标记为'0'，避免重复计数。
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            // 越界或不是陆地，返回
            return;
        }

        // 标记为已访问（淹没）
        grid[i][j] = '0';
        // 向四个方向扩展
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    void Test()
    {
        vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        };
        cout << numIslands(grid) << endl;
    }
};

#endif /* _00__Number_of_Islands_h */