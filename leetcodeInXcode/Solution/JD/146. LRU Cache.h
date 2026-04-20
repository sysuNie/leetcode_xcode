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

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        auto it = cache[key];
        usage.erase(it);
        usage.push_front({key, it->second});
        cache[key] = usage.begin();

        return it->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            usage.erase(cache[key]);
        } else if (cache.size() >= cap) {
            auto last = usage.back();
            usage.pop_back();
            cache.erase(last.first);
        }

        usage.push_front({key, value});
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