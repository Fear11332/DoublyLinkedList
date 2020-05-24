
#include <iostream>
#include "practiclisttwo.h"

List::List()
{
    elements_counter = 0;
    head = nullptr;
    tail = nullptr;
}

void List::push_back(int data)
{

    Node* ptr = new Node(data);

    ptr->previous = tail;

    if (tail != nullptr) {
        tail->pnext = ptr;
    }

    if (elements_counter == 0) {
        head = tail = ptr;
    }

    else {
        tail = ptr;
    }

    elements_counter++;
}

List::~List()
{
    while (head) {
        tail = head->pnext;
        delete head;
        head = tail;
    }
}

ValueType List::operator[](const size_t index)
{

    int counter = 0;
    ValueType buffer;
    Node* current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            buffer = current->data;
            break;
        }

        current = current->pnext;
        counter++;
    }

    return buffer;
}

void List::remove_front()
{
    Node* temp = head;
    head = head->pnext;
    head->previous = nullptr;

    delete temp;
    elements_counter--;
}

void List::clear()
{
    while (head) {
        tail = head->pnext;
        delete head;
        head = tail;
        elements_counter--;
    }
}

void List::push_front(int data)
{
    Node* ptr = new Node(data);

    ptr->previous = nullptr;
    ptr->pnext = head;

    if (head != nullptr) {
        head->previous = ptr;
    }

    if (elements_counter == 0) {
        head = tail = ptr;
    }

    else {
        head = ptr;
    }

    elements_counter++;
}

void List::insert(int value, size_t index)
{

    if (index == 1) {
        push_front(value);
    }

    else if (index == elements_counter + 1) {
        push_back(value);
    }

    else if (index > 1 && index < elements_counter) {

        if (index <= elements_counter / 2) {

            Node* previous = this->head;

            for (int i = 0; i < index - 2; i++) {
                previous = previous->pnext;
            }

            Node* newNode = new Node(value, previous->previous, previous->pnext);
            previous->pnext = newNode;

            elements_counter++;
        }

        else {

            Node* previous = this->tail;

            size_t count = 0;

            while (index != elements_counter - count + 1) {
                previous = previous->previous;
                count++;
            }

            Node* newNode = new Node(value, previous->previous, previous->pnext);
            previous->pnext = newNode;

            elements_counter++;
        }
    }
}

void List::removeAt(size_t index)
{
    if (index > 0 && index <= elements_counter) {

        if (index == 1) {
            remove_front();
        }

        else if (index == elements_counter) {
            remove_back();
        }

        else {
            if (index <= elements_counter / 2) {

                Node* current = this->head;

                for (int i = 0; i < index - 2; i++) {
                    current = current->pnext;
                }

                Node* toDelete = current->pnext;
                current->pnext = toDelete->pnext;
                current = toDelete->pnext;
                current->previous = toDelete->previous;

                delete toDelete;
                elements_counter--;
            }

            else {

                Node* current = this->tail;

                size_t count = elements_counter;

                for (int i = 0; i < count - index + 1; i++) {

                    current = current->previous;
                }

                Node* toDelete = current->pnext;
                current->pnext = toDelete->pnext;
                current = toDelete->pnext;
                current->previous = toDelete->previous;

                delete toDelete;
                elements_counter--;
            }
        }
    }
}

void List::remove_back()
{
    Node* temp = tail;
    tail = tail->previous;
    tail->pnext = nullptr;

    delete temp;
    elements_counter--;
}

List::Node* List::getNode(const size_t pos) const
{

    if (pos <= elements_counter && pos > 0) {

        if (pos <= elements_counter / 2) {

            Node* current = this->head;

            for (int i = 0; i < pos - 1; ++i) {
                current = current->pnext;
            }
            return current;
        }

        else {

            Node* current = this->tail;

            for (int i = 0; i < elements_counter - pos; i++) {
                current = current->previous;
            }

            return current;
        }
    }

    else {
        return 0;
    }
}

void List::removeNextNode(Node* node)
{
    if (node->pnext == nullptr) {
    }

    else {

        Node* Delete = node->pnext;

        if (Delete->pnext == nullptr) {
            node->pnext = nullptr;
            tail = node;
            elements_counter--;
            delete Delete;
        }

        else {

            node->pnext = Delete->pnext;
            Node* newnext = Delete->pnext;
            newnext->previous = Delete->previous;

            delete Delete;
            elements_counter--;
        }
    }
}

void List::removeNext(size_t pos)
{
    if (pos == elements_counter) {
        remove_back();
    }

    else {
        removeAt(pos);
    }
}

void List::insertAfterNode(Node* node, const ValueType& value)
{
    Node* newNode = new Node(value);

    if (node->pnext == nullptr) {

        node->pnext = newNode;
        newNode->previous = node;
        newNode->pnext = nullptr;
        tail = newNode;
        elements_counter++;
    }

    else {
        Node* current = node->pnext;
        node->pnext = newNode;
        newNode->pnext = current;
        current->previous = newNode;
        newNode->previous = node;
        elements_counter++;
    }
}

void List::Node::insertNext(const ValueType& value)
{
    Node* newNode = new Node(value, this->previous, this->pnext);
    this->pnext = newNode;
}

long long int List::findIndex(const ValueType& value) const
{
    Node* current = this->head;
    Node* current2 = this->tail;
    long long int counter = 0;
    long long int counter2 = 0;

    if (current->data == value) {
        return ++counter;
    }

    else {

        while (current->pnext != nullptr) {
            current = current->pnext;
            counter++;

            if (current->data == value) {
                return ++counter;
            }
        }
    }

    return 0;
}

List::Node* List::findNode(const ValueType& value) const
{
    Node* current = this->head;
    Node* current2 = this->tail;

    if (current->data == value) {
        return current;
    }

    else {

        while (current->pnext != nullptr) {
            current = current->pnext;

            if (current->data == value) {
                return current;
            }
        }

        while (current2->previous != nullptr) {
            current2 = current2->previous;

            if (current2->data == value) {
                return current2;
            }
        }
    }

    return 0;
}

void List::reverse()
{
    Node* previous = nullptr;
    Node* current = this->head;
    Node* following = this->head;

    while (current != nullptr) {
        following = following->pnext;
        current->pnext = previous;
        previous = current;
        current = following;
    }

    this->head = previous;

    previous = nullptr;
    current = this->tail;
    following = this->tail;

    while (current != nullptr) {
        following = following->previous;
        current->previous = previous;
        previous = current;
        current = following;
    }

    this->tail = previous;
}

List& List::operator=(const List& copyList)
{
    if (this == &copyList) {
        return *this;
    }

    List bufList(copyList);
    this->elements_counter = bufList.elements_counter;
    this->head = bufList.head;
    this->tail = bufList.tail;

    return *this;
}

List::List(const List& copyList)
{
    this->elements_counter = copyList.elements_counter;
    if (this->elements_counter == 0) {
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }

    this->head = new Node(copyList.head->data);
    this->tail = copyList.tail;

    Node* currentNode = this->head;
    Node* currentCopyNode = copyList.head;
    Node* currentNode2 = this->tail;
    Node* currentCopyNode2 = copyList.tail;

    while (currentCopyNode->pnext) {
        currentNode->pnext = new Node(currentCopyNode->pnext->data);
        currentCopyNode = currentCopyNode->pnext;
        currentNode = currentNode->pnext;

        currentNode2->previous = currentCopyNode2->previous;
        currentCopyNode2 = currentCopyNode2->previous;
        currentNode2 = currentNode2->previous;
    }
}

List List::reverse() const
{
    List reversed(*this);
    reversed.reverse();

    return reversed;
}

List List::getReverseList() const
{
    List reversed = (*this);
    reversed.reverse();

    return reversed;
}

List& List::operator=(List&& moveList) noexcept
{
    if (this == &moveList) {
        return *this;
    }
    removeAt(1);
    this->elements_counter = moveList.elements_counter;
    this->head = moveList.head;

    moveList.elements_counter = 0;
    moveList.head = nullptr;

    return *this;
}

List::List(List&& moveList) noexcept
{
    this->elements_counter = moveList.elements_counter;
    this->head = moveList.head;

    moveList.elements_counter = 0;
    moveList.head = nullptr;
}

void List::forceNodeDelete(Node* node)
{
    if (node == nullptr) {
        return;
    }

    Node* nextDeleteNode = node->pnext;
    delete node;
    forceNodeDelete(nextDeleteNode);
}

size_t List::GetElementsCounter()
{
    return elements_counter;
}
