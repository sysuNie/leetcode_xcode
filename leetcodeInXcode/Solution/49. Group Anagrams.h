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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, int, ArrayHash> map;
        vector<vector<string>> ans;
        int index = 0;
        for(auto str : strs) {
            array<int, 26> count = {0};
            for(auto c : str) {
                count[c - 'a']++;
            }
            if(map.find(count) != map.end()) {
                ans[map[count]].push_back(str);
            }
            else {
                map[count] = index++;
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
