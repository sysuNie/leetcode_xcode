//
//  146. LRU Cache.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _46__LRU_Cache_h
#define _46__LRU_Cache_h

class LRUCache {
private:
    int cap;
    list<pair<int, int>> usage; // 链表存 {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        // 关键点：使用 splice 将 it 节点移动到链表头部
        // usage.splice(目的地迭代器, 原链表, 要移动的节点迭代器)
        usage.splice(usage.begin(), usage, cache[key]);
        // 移动后，哈希表中对应的迭代器位置依然有效！
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // key已存在，更新值并移到头部
            cache[key]->second = value; // 更新value
            usage.splice(usage.begin(), usage, cache[key]); // 移动
        } else {
            // key不存在
            if (usage.size() >= cap) {
                // 淘汰最久未使用的元素 (队尾)
                int oldestKey = usage.back().first;
                cache.erase(oldestKey);
                usage.pop_back();
            }
            // 插入新元素到头部
            usage.push_front({key, value});
            cache[key] = usage.begin();
        }
    }
};


class LRUCache1 {
private:
    int cap;
    std::list<std::pair<int, int>> m_list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_map;

public:
    LRUCache1(int capacity) : cap(capacity) { }

    int get(int key) {
        auto it = m_map.find(key);
        if (it == m_map.end()) return -1;
        m_list.splice(m_list.begin(), m_list, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m_map.find(key);
        if (it != m_map.end())
        {
            it->second->second = value;
            m_list.splice(m_list.begin(), m_list, it->second);
            return;
        }
        else
        {
            if (m_map.size() == cap) {
                m_map.erase(m_list.back().first);
                m_list.pop_back();
            }
            m_list.emplace_front(key, value);
            m_map[key] = m_list.begin();
        }
    }
};

class Solution {
public:
    void Test()
    {
        LRUCache* obj = new LRUCache(2);
        obj->put(1, 1);
        obj->put(2, 2);
        cout << obj->get(1) << endl;
        obj->put(3, 3);
        cout << obj->get(2) << endl;
    }
};

#endif /* _46__LRU_Cache_h */
