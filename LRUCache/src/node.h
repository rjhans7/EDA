#pragma once
#include <bits/stdc++.h>
#include <optional>

using namespace std;

template <typename K, typename V>
class DLinkedList;

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

    friend class DLinkedList <K, V>;
};
