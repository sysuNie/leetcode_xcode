//
//  240. Search a 2D Matrix II.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _40__Search_a_2D_Matrix_II_h
#define _40__Search_a_2D_Matrix_II_h

class Solution {
public:
    // 思路：利用矩阵行递增、列递增的特性。从右上角开始：
    // 若当前值大于target则左移（减小），小于target则下移（增大）。
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        // 从右上角开始
        int col = cols - 1;

        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                // 找到目标
                return true;
            } else if (matrix[row][col] > target) {
                // 当前值太大，向左移动
                col--;
            } else {
                // 当前值太小，向下移动
                row++;
            }
        }

        // 越界未找到
        return false;
    }

    void Test()
    {
        vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        int target = 5;
        cout << (searchMatrix(matrix, target) ? "true" : "false") << endl;
    }
};

#endif /* _40__Search_a_2D_Matrix_II_h */