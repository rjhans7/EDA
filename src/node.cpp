#include "node.h"

template <typename K, typename V>
Node<K, V>::Node()
{
    this->timestamp = 0;
    this->next = this->prev = nullptr;
}

template <typename K, typename V>
Node<K, V>::Node(K key, V value)
{
    this->key = key;
    this->value = value;
    this->next = this->prev = nullptr;
    this->timestamp = 0;
}

template <typename K, typename V>
void Node<K, V>::showKeyValue()
{
    cout << "------------------------" << endl;
    cout << "Timestamp: " << this->timestamp << endl;
    cout << "Key: " << this->key << endl;
    cout << "Value: " << this->value << endl;
    cout << "------------------------" << endl;
}

template <typename K, typename V>
Node<K, V>::~Node()
{
    //TODO    
}