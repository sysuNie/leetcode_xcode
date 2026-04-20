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
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j>= grid[0].size()|| grid[i][j]==0)
        {
            return 0;
        }
        int sum = 1;
        grid[i][j] = 0;
        //遍历上方元素，每遍历一次陆地就加一
        sum += dfs(grid, i + 1, j);
        //遍历下方元素
        sum +=dfs(grid, i - 1, j);
        //遍历右边元素
        sum +=dfs(grid, i, j + 1);
        //遍历左边元素
        sum += dfs(grid, i, j - 1);
        return sum;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
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
