#pragma once

template<class T>
class Queue {
public:
	class Node {
		Node*next;
		T data;
	public:
		// Linked list node Implementation goes here...
	};
	Queue() :list(0), tail(0), size(0){};
	Queue(const Queue& a_rPointer);
	~Queue();
	//Accessory functions
	bool Empty()const;
	unsigned int GetSize()const;
	//Access functions
	void Push(T& a_rValue);
	const T& Pop();
	const T& Top();
private:
	Node*list;
	Node*tail;
	unsigned int size;
};
 
