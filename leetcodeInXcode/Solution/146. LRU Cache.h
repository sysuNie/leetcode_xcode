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
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    // 思路：使用双向链表维护访问顺序（最近访问在头部），配合哈希表实现O(1)查找。
    // 访问或插入时将节点移到链表头部，超出容量时淘汰尾部节点。
    int get(int key) {
        // key不存在
        if (cache.find(key) == cache.end()) return -1;

        auto it = cache[key];
        // 从原位置删除
        usage.erase(it);
        // 移到链表头部（最近使用）
        usage.push_front({key, it->second});
        // 更新哈希表中的迭代器
        cache[key] = usage.begin();

        return it->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // key已存在，删除旧节点
            usage.erase(cache[key]);
        } else if (cache.size() >= cap) {
            // 淘汰最久未使用的尾部节点
            auto last = usage.back();
            usage.pop_back();
            cache.erase(last.first);
        }

        // 插入到头部（最新使用）
        usage.push_front({key, value});
        // 更新哈希表
        cache[key] = usage.begin();
    }

private:
    int cap;
    list<pair<int, int>> usage;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
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