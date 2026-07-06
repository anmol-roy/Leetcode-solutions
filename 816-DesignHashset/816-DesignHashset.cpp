// Last updated: 06/07/2026, 09:53:49
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class MyHashSet {
private:
    // Declare M and buckets here so ALL functions inside the class can see them
    int M = 15000;
    vector<list<int>> buckets;

    int getIndex(int key) {
        return key % M;
    }

public:
    MyHashSet() {
        // Correctly resize the bucket array to size M
        buckets.resize(M);
    }
    
    void add(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);
        if(itr == buckets[index].end()){
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);
        if(itr != buckets[index].end()){
            buckets[index].erase(itr);
        }
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);
        // Corrected: Returns true if itr is NOT at the end (meaning it WAS found)
        return itr != buckets[index].end();
    }
};
