//
//  207. hasCycle.h
//  leetcodeInXcode
//
//  Created by niejikang on 23.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _07__hasCycle_h
#define _07__hasCycle_h


unordered_map<string, vector<string>> buildGraph(std::vector<pair<string, string>>& service_relations)
{
    unordered_map<string, vector<string>> graph;
    
    for(auto [from, to] : service_relations)
    {
        graph[from].push_back(to);
        if (!graph.count(to)) {
            graph[to] = {};
        }
    }
    
    return graph;
}

bool dfs(unordered_map<string, vector<string>>& graph, unordered_map<std::string, int>& color, const std::string& service)
{
    color[service] = 1;
    
    for (auto& next : graph.at(service))
    {
        if (color[next] == 1) {
            return true;
        }
        if (color[next] == 0) {
            if (dfs(graph, color, next))
            {
                return true;
            }
        }
    }
    
    color[service] = 2;
    return false;
}

bool hasCycle(std::vector<pair<string, string>>& service_relations)
{
    auto graph = buildGraph(service_relations);
    
    unordered_map<std::string, int> color;
    
    for (auto& gr : graph)
    {
        if (color[gr.first] == 0) {
            if (dfs(graph, color, gr.first)) {
                return true;
            }
        }
    }
    
    return false;
}

#endif /* _07__hasCycle_h */
