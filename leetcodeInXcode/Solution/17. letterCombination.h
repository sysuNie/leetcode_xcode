//
//  17. letterCombination.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _7__letterCombination_h
#define _7__letterCombination_h

class Solution {
public:
    string ds;
    int vols[10] = {0,0,3,3,3,3,3,4,3,4};
    vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    
    // 思路：回溯/深度优先搜索。对每个数字按键，枚举其对应的所有字母，
    // 递归处理下一个数字，直到遍历完所有数字，得到一种完整组合。
    vector<string> letterCombinations(string digits) {
        ans.clear();
        ds = digits;
        vector<int> ptrs(digits.length(), 0);
        if(digits.length()==0)
            // 空输入直接返回空结果
            return ans;
        // 从第0个数字开始递归
        getDeeper(ptrs, 0);
        
        return ans;
    }
    
    void getDeeper(vector<int> &ptrs, int deepNess){
        if(deepNess >= ds.length()){
            string s;
            for(int i=0;i;i<ds.length();i++){
                // 根据指针取出每个数字对应的字母
                s += phone[ds[i]-'2'][ptrs[i]];
            }
            // 记录一种完整组合
            ans.push_back(s);
            return;
        }
        // 当前数字对应的按键索引（2对应0）
        int thisButton = ds[deepNess]-'2';
        // 当前按键的字母数
        int choicesNumInThisButton = phone[thisButton].length();
        for(int i=0;i;i<choicesNumInThisButton;i++){
            // 递归处理下一个数字
            getDeeper(ptrs, deepNess+1);
            // 切换到当前按键的下一个字母
            ptrs[deepNess] = (ptrs[deepNess]+1) % choicesNumInThisButton;
        }
        
        return;
    }
    
    void getDeeper(vector<int> &ptrs, int deepNess){
        if(deepNess >= ds.length()){
            string s;
            for(int i=0;i<ds.length();i++){
                s += phone[ds[i]-'2'][ptrs[i]];
            }
            ans.push_back(s);
            return;
        }
        int thisButton = ds[deepNess]-'2';
        int choicesNumInThisButton = phone[thisButton].length();
        for(int i=0;i<choicesNumInThisButton;i++){
            getDeeper(ptrs, deepNess+1);
            ptrs[deepNess] = (ptrs[deepNess]+1) % choicesNumInThisButton;
        }
        
        return;
    }
    
    void Test()
    {
        vector<string> ansmain = letterCombinations("");
        for(int i=0;i<ansmain.size();i++){
            cout << ansmain[i] << endl;
        }
    }
};

#endif /* _7__letterCombination_h */
