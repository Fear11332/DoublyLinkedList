#include <cstddef>
#ifndef PRACTICLISTTWO_H
#define PRACTICLISTTWO_H

using ValueType = double;

class List {
    class Node {
    public:
        
		Node* previous;
        Node* pnext;
        ValueType data;

        Node(ValueType data = ValueType(), Node* previous = nullptr, Node* pnext = nullptr)
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
    void removeNextNode(Node* node);
	void remove_back();
	 
	void push_back(ValueType data);
    void push_front(ValueType data);
	
	size_t GetElementsCounter();
    
	void clear();
    void removeAt(size_t index);
	void removeNext(size_t pos);
	void forceNodeDelete(Node* node);
	
    void insert(ValueType value, size_t index);
    void insertAfterNode(Node* node, const ValueType& value);
	
    Node* getNode(const size_t pos) const;
    
    long long int findIndex(const ValueType& value) const;
    Node* findNode(const ValueType& value) const;
    
	void reverse();
    List reverse() const;
	
	List& operator=(const List& copyList);
    ValueType operator[](const size_t index);
	List(const List& copyList);
    List getReverseList() const;
    List& operator=(List&& moveList) noexcept;
    List(List&& moveList) noexcept;
    
private:
    Node* tail;
    Node* head;

    size_t elements_counter;
};

#endif
