//
//  64. Minimum Path Sum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _4__Minimum_Path_Sum_h
#define _4__Minimum_Path_Sum_h

class Solution {
public:
    // 思路：动态规划。path[i][j] 表示从左上角到 (i,j) 的最小路径和，
    // 只能从上方或左方到达，状态转移取两者最小值加上当前格子值。
    int minPathSum(vector<vector<int>>& grid) {
        // dp 数组
        vector<vector<int>> path(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < path.size(); ++i) {
            for(int j = 0; j < path[i].size(); ++j) {
                if(i == 0 && j == 0) {
                    // 起点初始化
                    path[i][j] = grid[i][j];
                    continue;
                }
                // 上方和左方取较小值，边界情况用 INT_MAX 排除
                path[i][j] = min(i == 0 ? INT_MAX : path[i - 1][j], j == 0 ? INT_MAX : path[i][j - 1]) + grid[i][j];
            }
        }
        // 返回右下角最小路径和
        return path[path.size() - 1][path[0].size() - 1];
    }

    void Test()
    {
        vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
        cout << minPathSum(grid) << endl;
    }
};


#endif /* _4__Minimum_Path_Sum_h */
