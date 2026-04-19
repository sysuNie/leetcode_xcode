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
    vector<double> calcEquation(vector<pair<string, string>>& equations,
                               vector<double>& values,
                               vector<pair<string, string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

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
            dfs(graph, start, end, 1.0, visited, ans);
            result.push_back(ans);
        }

        return result;
    }

    void dfs(unordered_map<string, vector<pair<string, double>>>& graph,
             string& curr, string& target, double acc,
             unordered_set<string>& visited, double& ans) {
        if (visited.count(curr)) return;
        if (curr == target) {
            ans = acc;
            return;
        }

        visited.insert(curr);
        for (auto& neighbor : graph[curr]) {
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