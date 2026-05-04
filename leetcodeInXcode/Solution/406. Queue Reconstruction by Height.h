//
//  406. Queue Reconstruction by Height.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _06__Queue_Reconstruction_by_Height_h
#define _06__Queue_Reconstruction_by_Height_h

class Solution {
public:
    // 思路：先按身高降序、同身高按前面人数升序排序。然后依次将每个人插入到结果数组的指定位置（person[1]），高个子先插入不会影响后续矮个子的相对位置。
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 按身高降序排列，身高相同则按前面人数升序排列
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> result;
        for (auto& person : people) {
            // 将当前人插入到指定位置
            result.insert(result.begin() + person[1], person);
        }

        return result;
    }

    void Test()
    {
        vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
        vector<vector<int>> result = reconstructQueue(people);
        for (const auto& p : result) {
            cout << p[0] << " " << p[1] << endl;
        }
    }
};

#endif /* _06__Queue_Reconstruction_by_Height_h */