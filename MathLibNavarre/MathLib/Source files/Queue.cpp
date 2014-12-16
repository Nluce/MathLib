#include "Queue.h"

template<class T>
Queue<T>::~Queue()
{
	while (list)
	{
		Pop();
	}
}
template<class T>
void Queue<T>::Push(T& a_rValue)
{
	//Create a new node, and set a_rValue to be its data
	//Attach the new node to the end of the linked list
	Node*n new Node();
	n->data = a_rValue;
	n->next = 0;
	if (tail)
	{
		tail->next = n;
	}
	if (!list)
	{
		list = n;
	}
	tail = n;
	size++;
}
template<class T>
const T& Queue<T>::Pop()
{
	//Remove the head of the linked list and set its child to
	//be the new head
	Node*n = list;
	T data = n->data;
	list = n->next;
	delete n;
	return data;

}
template<class T>
const T& Queue<T>::Top()
{
	//Return the data stored in the head of the linked list
	return list->data;
}