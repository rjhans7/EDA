#include "src/lru.cpp"

int main()
{
    DLinkedList<char, int> myDlinkedList(3);
    myDlinkedList.insertKeyValuePair('b', 2);
    myDlinkedList.insertKeyValuePair('a', 1);
    myDlinkedList.insertKeyValuePair('c', 3);
    myDlinkedList.getMostRecentKey();
    myDlinkedList.getValueFromKey('a');
    myDlinkedList.getMostRecentKey();
    myDlinkedList.insertKeyValuePair('d', 4);
    myDlinkedList.getValueFromKey('b');
    myDlinkedList.insertKeyValuePair('a', 5);
    myDlinkedList.getValueFromKey('a');
    myDlinkedList.showAllKeyValuePairs();
}