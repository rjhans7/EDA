#include "src/lru.cpp"

int main()
{
    LRUCache<char, int> myLRUCache(3);
    myLRUCache.insertKeyValuePair('b', 2);
    myLRUCache.insertKeyValuePair('a', 1);
    myLRUCache.insertKeyValuePair('c', 3);
    myLRUCache.getMostRecentKey();
    myLRUCache.getValueFromKey('a');
    myLRUCache.getMostRecentKey();
    myLRUCache.insertKeyValuePair('d', 4);
    myLRUCache.getValueFromKey('b');
    myLRUCache.insertKeyValuePair('a', 5);
    myLRUCache.getValueFromKey('a');
    myLRUCache.showAllKeyValuePairs();
}