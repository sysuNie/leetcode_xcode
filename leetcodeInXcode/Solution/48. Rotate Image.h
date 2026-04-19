//
//  48. Rotate Image.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _8__Rotate_Image_h
#define _8__Rotate_Image_h

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[i].size() - i; ++j) {
                swap(matrix[i][j], matrix[matrix[i].size() - 1 - j][matrix.size() - 1 - i]);
            }
        }
        for(int i = 0; i < matrix.size() / 2; ++i) {
            for(int j = 0; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[matrix.size() - 1 - i][j]);
            }
        }
    }

    void Test()
    {
        vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
        rotate(matrix);
        for(const auto& row : matrix) {
            for(int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

#endif /* _8__Rotate_Image_h */
