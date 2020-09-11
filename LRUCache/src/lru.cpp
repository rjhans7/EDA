#include "lru.h"

template <typename K, typename V>
DLinkedList<K, V>::DLinkedList(long maxSize)
{
    this->maxSize = maxSize;
    this->head = this->tail = nullptr;
    this->initial_time = 1;
    this->elements = 0;
}

template <typename K, typename V>
void DLinkedList<K, V>::insertKeyValuePair(K key, V value)
{
    if (this->hash_map.find(key) != this->hash_map.end())
    {
        cout << "\n**** Updating value for key ****" << endl;
        Node <K, V>* tempNode = this->hash_map[key];
        tempNode->value = value;
        this->updateLeastRecently(tempNode);      
        tempNode->showKeyValue();
    }
    else
    {
        cout << "\n**** Inserting key value ****" << endl;
        Node <K, V>* newNode = new Node<K, V> (key, value);
        newNode->timestamp = this->initial_time;
        this->hash_map[key] = newNode;
        newNode->showKeyValue();
        if (this->head)
        {
            if (this->head == this->tail)
            {
                this->head->next = newNode;
                this->head->prev = newNode;
                newNode->next = this->head;
                newNode->prev = this->head;
                this->tail = newNode;
            }
            else
            {
                if (this->maxSize == this->elements)
                {
                    cout << "\n******* Eviction ********" << endl;
                    Node <K, V>* tempNode = this->head;
                    this->head = this->head->next;
                    this->head->prev = this->tail;
                    this->tail->next = this->head;
                    tempNode->showKeyValue();
                    this->hash_map.erase(tempNode->key);
                    this->elements--;
                    delete tempNode;
                }
                this->tail->next = newNode;
                newNode->prev = this->tail;
                newNode->next = this->head;
                this->head->prev = newNode;
                this->tail = newNode;
            }   
        }
        else
        {
            this->head = this->tail = newNode;
        }
        this->elements++;
        this->initial_time++;
    }
}

template <typename K, typename V>
K DLinkedList<K, V>::getMostRecentKey()
{
    cout << "\n****** Most recent key ******" << endl;
    this->tail->showKeyValue();
    return this->tail->key;
}

template <typename K, typename V>
void DLinkedList<K, V>::updateLeastRecently(Node<K, V>* tempNode)
{
    if (tempNode != this->tail)
    {
        tempNode->prev->next = tempNode->next;
        tempNode->next->prev = tempNode->prev;
        if (tempNode == this->head)
            this->head = tempNode->next;
        
        tempNode->next = this->head;
        tempNode->prev = this->tail;
        this->tail->next = tempNode;
        this->head->prev = tempNode;
        this->tail = tempNode;
    }
    tempNode->timestamp = this->initial_time;
    this->initial_time++;    
}

template <typename K, typename V>
V DLinkedList<K, V>::getValueFromKey(K key)
{
    cout << "\n**** Get value from key ****" << endl;
    if (hash_map.find(key) != hash_map.end())
    {
        Node <K, V>* tempNode = hash_map[key];
        this->updateLeastRecently(tempNode);
        tempNode->showKeyValue();
        return tempNode->value;
    }
    else
    {
        cout << "None" << endl;
        return {};
    }
}

template <typename K, typename V>
void DLinkedList<K, V>::showAllKeyValuePairs()
{
    cout << "======== Showing all elements =======" << endl;
    Node <K,V> * tempNode = this->head;
    for (int i = 0; i < this->maxSize; i++)
    {
        tempNode->showKeyValue();
        tempNode = tempNode->next;
    }
}