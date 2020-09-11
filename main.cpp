#include "src/lru.cpp"

int main()
{
    DLinkedList<char, int> myDlinkedList(3);
    myDlinkedList.insertKeyValuePair('b', 2);
    myDlinkedList.insertKeyValuePair('a', 1);
    myDlinkedList.insertKeyValuePair('c', 3);
    cout << myDlinkedList.getMostRecentKey() << endl;
    cout << myDlinkedList.getValueFromKey('a') << endl;
    cout << myDlinkedList.getMostRecentKey() << endl;
    myDlinkedList.insertKeyValuePair('d', 4);
    cout << myDlinkedList.getValueFromKey('b') << endl;
    myDlinkedList.insertKeyValuePair('a', 5);
    cout << myDlinkedList.getValueFromKey('a') << endl;
    myDlinkedList.showAllKeyValuePairs();
}