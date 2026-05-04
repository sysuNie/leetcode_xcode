//
//  695. Max Area OfIsland.h
//  leetcodeInXcode
//
//  Created by niejikang on 20.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _95__Max_Area_OfIsland_h
#define _95__Max_Area_OfIsland_h

class Solution {
public:
    // 思路：DFS深度优先搜索。从当前陆地出发，向上下左右四个方向扩展，
    //       将访问过的陆地标记为0避免重复计算，返回当前岛屿的面积。
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j>= grid[0].size()|| grid[i][j]==0)
        {
            // 越界或遇到水域，返回面积0
            return 0;
        }
        // 当前陆地贡献面积1
        int sum = 1;
        // 标记为已访问（沉岛），防止重复计算
        grid[i][j] = 0;
        // 向四个方向递归搜索并累加面积
        // 下方
        sum += dfs(grid, i + 1, j);
        // 上方
        sum += dfs(grid, i - 1, j);
        // 右方
        sum += dfs(grid, i, j + 1);
        // 左方
        sum += dfs(grid, i, j - 1);
        return sum;
    }
    
    // 思路：遍历矩阵每个位置，遇到陆地（值为1）则以该点为起点进行DFS，
    //       统计该连通块的面积，取所有岛屿面积的最大值。
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // 发现新岛屿的起点
                if (grid[i][j] == 1) {
                    // 更新最大岛屿面积
                    res = std::max(res, dfs(grid, i, j));
                }
            }
        }
        
        return res;
    }

    void Test()
    {
        
    }
};


#endif /* _95__Max_Area_OfIsland_h */
