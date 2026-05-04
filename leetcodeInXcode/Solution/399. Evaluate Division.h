//
//  399. Evaluate Division.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _99__Evaluate_Division_h
#define _99__Evaluate_Division_h

class Solution {
public:
    // 思路：将除法等式构建为带权有向图，a/b=val 表示 a→b 边权为 val，b→a 边权为 1/val。对每个查询用 DFS 搜索路径，路径上边权的乘积即为答案。
    vector<double> calcEquation(vector<pair<string, string>>& equations,
                               vector<double>& values,
                               vector<pair<string, string>>& queries) {
        // 邻接表存储带权图
        unordered_map<string, vector<pair<string, double>>> graph;

        // 建图：a/b=val 对应 a→b 权 val，b→a 权 1/val
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i].first;
            string b = equations[i].second;
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> result;
        for (auto& query : queries) {
            string start = query.first;
            string end = query.second;
            unordered_set<string> visited;
            double ans = -1.0;
            // DFS 搜索从 start 到 end 的路径
            dfs(graph, start, end, 1.0, visited, ans);
            result.push_back(ans);
        }

        return result;
    }

    // DFS 搜索从 curr 到 target 的路径，acc 为当前累积的边权乘积
    void dfs(unordered_map<string, vector<pair<string, double>>>& graph,
             string& curr, string& target, double acc,
             unordered_set<string>& visited, double& ans) {
        // 避免重复访问
        if (visited.count(curr)) return;
        if (curr == target) {
            // 找到目标，更新答案
            ans = acc;
            return;
        }

        visited.insert(curr);
        for (auto& neighbor : graph[curr]) {
            // 累积边权继续搜索
            dfs(graph, neighbor.first, target, acc * neighbor.second, visited, ans);
        }
    }

    void Test()
    {
        vector<pair<string, string>> equations = {{"a", "b"}, {"b", "c"}};
        vector<double> values = {2.0, 3.0};
        vector<pair<string, string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

        vector<double> result = calcEquation(equations, values, queries);
        for (double d : result) {
            cout << d << " ";
        }
        cout << endl;
    }
};

#endif /* _99__Evaluate_Division_h */
