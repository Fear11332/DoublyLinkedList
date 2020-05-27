
#include <iostream>
#include "practiclisttwo.h"

using namespace std;

int main()
{
    List lst;
    size_t numbers_count;

    cout << "enter list size" << endl;
    cin >> numbers_count;
    cout << endl;

    for (int i = 0; i < numbers_count; i++) {
        lst.push_back(rand()%10);
    }

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "remove_front" << endl;
    lst.remove_front();

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "push_front" << endl;
    lst.push_front(5);

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << endl;
    size_t index;
    double value;
    cout << "enter position and value for insert" << endl;
    cin >> index >> value;
    cout << "insert position:" << index << " value=" << value << endl;
    lst.insert(value, index);

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "remove_back" << endl;
    lst.remove_back();

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "enter position for remove" << endl;
    cin >> index;
    cout << "remove element in position:" << index << endl;
    lst.removeAt(index);

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "enter position for getNode address" << endl;
    cin >> index;
    cout << "at the indicated position the Node has an address: " << lst.getNode(index);

    cout << endl;
    cout << endl;
    cout << "enter position for removeNextNode" << endl;
    cin >> index;
    cout << "remove node in position:" << index + 1 << endl;
    lst.removeNextNode(lst.getNode(index));

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "enter position for removeNext" << endl;
    cin >> index;
    cout << "remove element in position:" << index + 1 << endl;
    lst.removeNext(index + 1);

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << endl;
    ValueType value2;
    cout << "enter position and value for insertAfterNode" << endl;
    cin >> index >> value2;
    cout << "insert node after position :" << index << endl;
    lst.insertAfterNode(lst.getNode(index), value2);

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }

    cout << endl;
    cout << "enater your value for find index " << endl;
    cin >> value2;
    cout << "your index for value = " << value2 << " is: " << lst.findIndex(value2) << endl;

    cout << endl;
    cout << endl;
    cout << "enater your value for find node " << endl;
    cin >> value2;
    cout << "your node address for value = " << value2 << " is: " << lst.findNode(value2) << endl;

    cout << endl;
    cout << endl;
    cout << "reverse list " << endl;
    lst.reverse();

    cout << "list size = " << lst.GetElementsCounter() << endl;

    for (int i = 0; i < lst.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst[i] << endl;
    }
	
	cout << endl;
    cout << endl;
    cout << "copy constructor was called" << endl;
    List lst2(lst);

    cout << "list2 size = " << lst2.GetElementsCounter() << endl;

    for (int i = 0; i < lst2.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst2[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "reverse list2 " << endl;
    lst2.reverse();

    cout << "list2 size = " << lst2.GetElementsCounter() << endl;

    for (int i = 0; i < lst2.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst2[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "enter list3 size" << endl;
    cin >> numbers_count;
    List lst3;
    for (int i = 0; i < numbers_count; i++) {
        lst3.push_back(rand() % 10);
    }

    cout << "list3 size = " << lst3.GetElementsCounter() << endl;

    for (int i = 0; i < lst3.GetElementsCounter(); i++) {
        cout << "elements index " << i << '=';
        cout << lst3[i] << endl;
    }

    // cout<<endl;
    // cout<<endl;
    // cout<<"list = list3"<<endl;
    // lst = lst3;

    // cout<<"list size = "<<lst.GetElementsCounter()<<endl;

    // for(int i=0 ; i<lst.GetElementsCounter() ; i++)
    // {
    // cout<<"elements index "<<i<<'=';
    // cout<<lst[i]<<endl;
    // }

	

    cout << endl;
    cout << "clear all list:" << endl;
    lst.clear();
    lst2.clear();
    lst3.clear();

    cout << "list size = " << lst.GetElementsCounter() << endl;
    cout << "list2 size = " << lst2.GetElementsCounter() << endl;
    cout << "list3 size = " << lst3.GetElementsCounter() << endl;

    return 0;
}
