#include <cstdio>
#include <list>
#include <unordered_map>
#include <utility>
#include <memory>

class LRUCache
{
public:
    LRUCache() = default;
    LRUCache(int capacity) : cacheList(capacity), cacheCapacity{capacity}
    {
    }
    ~LRUCache() = default;
    int get(int key)
    {
        auto it = chacheMap.find(key);
        if (it == chacheMap.end())
        {
            printf("Key %d is not found\n", key);
            return -1;
        }
        cacheList.splice(cacheList.begin(), cacheList, it->second.second);
        return chacheMap[key].first;
    }
    void put(int key, int value)
    {
        auto itr = chacheMap.find(key);
        if (itr != chacheMap.end())
        {
            cacheList.splice(cacheList.begin(), cacheList, chacheMap[key].second);
        }
        else
        {
            if (cacheList.size() == cacheCapacity)
            {
                int LRU = cacheList.back();
                cacheList.pop_back();
                chacheMap.erase(LRU);
            }
            cacheList.push_front(key);
        }
        chacheMap[key] = std::make_pair(value, cacheList.begin());
    }

    void getChacheData() const
    {
        for (const auto &pair : chacheMap)
        {
            printf("Key %d has value with %d at address %p\n", pair.first, pair.second.first, &pair.second.second);
        }
    }

private:
    std::list<int> cacheList;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> chacheMap;
    int cacheCapacity;
};
int main(int argc, char const *argv[])
{
    std::unique_ptr<LRUCache> lRUCache = std::make_unique<LRUCache>(4);

    printf("Value for key %d: %d\n", 2, lRUCache->get(2));

    lRUCache->put(1, 5);
    lRUCache->put(2, 6);
    lRUCache->put(3, 8);
    lRUCache->put(1, 9);
    lRUCache->put(7, 9);
    lRUCache->put(8, 6);

    printf("Value for key %d: %d\n", 1, lRUCache->get(1));

    lRUCache->getChacheData();
    return 0;
}
