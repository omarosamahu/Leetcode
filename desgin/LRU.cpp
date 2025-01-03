#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <unordered_map>
#include <array>
#include <utility>
#include <algorithm>
#include <memory>

class LRUCache{
public:
    LRUCache() = default;
    LRUCache(int capacity):cacheList(capacity),cacheCapacity{capacity}{
    }
    ~LRUCache(){
        
    }
    int get(int key){
        auto it = chacheMap.find(key);
        if(it == chacheMap.end()){
            printf("Key %d is not found\n",key);
            return -1;
        }
        // Update the cache positions
        cacheList.splice(cacheList.begin(),cacheList, it->second.second);
        return chacheMap[key].first;
    }
    void put(int key,int value){
        // Put into map;
        auto itr = chacheMap.find(key);
        if(itr != chacheMap.end()){
            // Update value
            chacheMap[key].first = value;
            // Move it to the front
            cacheList.splice(cacheList.begin(),cacheList,chacheMap[key].second);
        }
        else{
        if(cacheList.size() == cacheCapacity){
            // Identify last element
            int LRU = cacheList.back();
            // Remove it from the list 
            cacheList.pop_back();
            // Remove it from the map
            chacheMap.erase(LRU);
        }
        // add it to the front
        cacheList.push_front(key);
        chacheMap[key] = std::make_pair(value,cacheList.begin());
        }
    }

    void display() const{
        for(const auto& cacheItem: cacheList){
            if(cacheItem != 0){
                printf("%d",cacheItem);
            }
        }
    }

    void getMapData() const {
        for(const auto& pair : chacheMap){
            printf("Key %d has value with %d at address %p\n",pair.first,pair.second.first,&pair.second.second);
        }
    }
private:
    std::list<int> cacheList;
    std::unordered_map<int,std::pair<int,std::list<int>::iterator>> chacheMap;
    int cacheCapacity;
};
int main(int argc, char const *argv[])
{
    std::unique_ptr<LRUCache> lRUCache = std::make_unique<LRUCache>(4);
    lRUCache->get(2);
    lRUCache->put(2,6);
    lRUCache->put(1,5);
    lRUCache->put(3,8);
    lRUCache->put(7,9);
    lRUCache->put(8,6);
    
    // lRUCache->display();   
    lRUCache->getMapData();
    return 0;
}
