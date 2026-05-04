//
//  49. Group Anagrams.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _9__Group_Anagrams_h
#define _9__Group_Anagrams_h

class Solution {
public:
    struct ArrayHash {
        size_t operator()(const std::array<int, 26>& arr) const {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ num;
            });
        }
    };
    // 思路：用字符计数数组作为哈希键，字母异位词具有相同的计数特征。
    // 使用unordered_map将相同键的字符串分到同一组。
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 计数数组到结果索引的映射
        unordered_map<array<int, 26>, int, ArrayHash> map;
        vector<vector<string>> ans;
        int index = 0;
        for(auto str : strs) {
            array<int, 26> count = {0};
            for(auto c : str) {
                // 统计每个字符出现次数
                count[c - 'a']++;
            }
            if(map.find(count) != map.end()) {
                // 已存在该键，加入对应分组
                ans[map[count]].push_back(str);
            }
            else {
                // 新键，分配新索引
                map[count] = index++;
                // 创建新分组
                ans.push_back({str});
            }
        }
        return ans;
    }

    void Test()
    {
        vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
        vector<vector<string>> result = groupAnagrams(strs);
        for(const auto& group : result) {
            for(const string& str : group) {
                cout << str << " ";
            }
            cout << endl;
        }
    }
};


#endif /* _9__Group_Anagrams_h */
