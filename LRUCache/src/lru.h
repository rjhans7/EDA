#include "node.cpp"

template<typename K, typename V>
class DLinkedList 
{
    Node<K, V>* head;
    Node<K, V>* tail;
    long initial_time, elements, maxSize;
    unordered_map<K, Node<K, V>*> hash_map;
    void updateLeastRecently(Node<K, V>* tempNode);

    public:
        explicit DLinkedList(long maxSize);
        void insertKeyValuePair(K key, V value);
        V getValueFromKey(K key);
        K getMostRecentKey();
        void showAllKeyValuePairs();
};
