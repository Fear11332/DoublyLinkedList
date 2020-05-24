#include <cstddef>
#ifndef PRACTICLISTTWO_H
#define PRACTICLISTTWO_H

using ValueType = double;

class List {
    class Node {
    public:
        Node* previous;
        Node* pnext;
        int data;

        Node(int data = int(), Node* previous = nullptr, Node* pnext = nullptr)
        {
            this->data = data;
            this->pnext = pnext;
            this->previous = previous;
        }
        void insertNext(const ValueType& value);
    };

public:
    List();
    ~List();
    void remove_front();
    void push_back(int data);
    size_t GetElementsCounter();
    ValueType operator[](const size_t index);
    void clear();
    void push_front(int data);
    void insert(int value, size_t index);
    void removeAt(size_t index);
    void remove_back();
    Node* getNode(const size_t pos) const;
    void removeNextNode(Node* node);
    void insertAfterNode(Node* node, const ValueType& value);
    long long int findIndex(const ValueType& value) const;
    Node* findNode(const ValueType& value) const;
    void reverse();
    List& operator=(const List& copyList);
    List(const List& copyList);
    List reverse() const;
    List getReverseList() const;
    List& operator=(List&& moveList) noexcept;
    List(List&& moveList) noexcept;
    void forceNodeDelete(Node* node);
    void removeNext(size_t pos);

private:
    Node* tail;
    Node* head;

    size_t elements_counter;
};

#endif
