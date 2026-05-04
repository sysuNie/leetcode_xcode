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
    // 思路：哈希表 + 双向链表。哈希表实现O(1)查找，链表维护访问顺序，
    //       队首为最近使用，队尾为最久未使用，超出容量时淘汰队尾。
    LRUCache(int capacity) {
        cap = capacity;
    }

    // 思路：若key存在，将其从链表原位置删除并移到队首，更新哈希表指向，返回对应value。
    int get(int key) {
        // key不存在直接返回-1
        if (cache.find(key) == cache.end()) return -1;

        auto it = cache[key];
        // 从原位置删除
        usage.erase(it);
        // 插入队首（最近使用）
        usage.push_front({key, it->second});
        // 更新哈希表指针
        cache[key] = usage.begin();

        return it->second;
    }

    // 思路：若key已存在则更新值并移到队首；若key不存在且容量已满，则淘汰队尾元素后再插入队首。
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // key已存在，删除旧位置
            usage.erase(cache[key]);
        } else if (cache.size() >= cap) {
            // 获取最久未使用的元素
            auto last = usage.back();
            // 淘汰队尾
            usage.pop_back();
            // 从哈希表中删除
            cache.erase(last.first);
        }

        // 插入队首
        usage.push_front({key, value});
        // 更新哈希表指针
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