# LRU Cache

To prove the following implementation just run the bash script `run.sh`. 

## Desing

We made use a STL **hash table** with a self-implementation of a **double linked list**. We use a hash table because this structure able us to get a the positions of a node by a key in $O(1)$ time. In the other side, we use a self-implementation of a double linked list because we have more control of the node pointers, can mantain a LRU policy, and made insert operation in $O(1)$. For the update operation in $O(1)$, we use the capacity of both structures, the hash map to get the position of the node and the double linked list to update the node values and acomplish the LRU policy. To have better performance, we have to pointers on the list, one at the beginnig (head or least recently) and one at the end (tail or most recently).

![design](img/design.drawio.png)

## Implementation

**Node**

```c++
template <typename K, typename V>
class Node 
{
    K key;
    V value;
    long timestamp;
    Node<K, V>* next;
    Node<K, V>* prev;

public:
    Node();
    Node(K key, V value);
    void showKeyValue();
    ~Node();

    friend class LRUCache <K, V>;
};

```

**LRU Cache**

```c++
template<typename K, typename V>
class LRUCache 
{
    Node<K, V>* head;
    Node<K, V>* tail;
    long initial_time, elements, maxSize;
    unordered_map<K, Node<K, V>*> hash_map;
    void updateLeastRecently(Node<K, V>* tempNode);

    public:
        explicit LRUCache(long maxSize);
        void insertKeyValuePair(K key, V value);
        optional <V> getValueFromKey(K key);
        K getMostRecentKey();
        void showAllKeyValuePairs();
};
```
The complete code is in the [src](/src) folder.

## Operations 
### Insertion

**Case 1:** first element

When a key value pair is the first element of the LRUCache, the `head` and `tail` will be the same of the **node**.

**Case 2:** second element

In this case, `head->next` and `head->prev` need to point the **new node**. In the same way `newNode->prev` and `newNode->next` need to point `head`. Finally the value of `tail` is updated to `newNode`.

**Case 3:** another element

In the same way as a double linked list, this node is added to the end of the list and the pointer will be updated.

**Case 3a:** eviction:

When we reach the `maxSize` variable, we need to **evict** the least recently, update the pointer and add the node in the same way of a double linked list.
        

### Update a Value

We get the position of the node using the `hash_map`, then we update the node's value and finally put the node at the end of the list.

### Update Least Recently

Every time we get access to a key, we change the position of the node to the end of the list while updating pointer and using the `head` and `tail` pointers.

### Search

Just we check the key in the `hash_map`.

## Analysis

- **Search:** as we use a hash table, the cost of access will be $O(1)$. In this operation we also made an update of the LRU element in $O(1)$ thanks to the `head` and `tail` pointers.
- **Insertion:** we have to pointers (head and tail) in a double linked list and we always insert a new element in the last node, so the cost will be $0(1)$
- **Update:** every time we need to update a value, we geet the position of the node in $O(1)$ using the `hash_map` and update its value in one operation. 