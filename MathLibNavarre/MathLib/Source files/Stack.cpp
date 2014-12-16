#include "Stack.h"
template<class T>
Stack<T>::Stack(unsigned int a_uiSize,
	unsigned int a_uiGrowSize = 1) :
	m_paData(NULL),
	m_uiSize(a_uiSize),
	m_uiGrowSize(a_uiGrowSize),
	m_iTop(-1)
{
	// Check the initial size is valid. 
	// If so, allocate memory
	if (m_uiSize) {
		// allocate memory and set all values to 0
		m_paData = new T[m_uiSize];
		memset(m_paData, 0, sizeof(T)* m_uiSize);
	}
}
template<class T>
Stack<T>::Stack(const Stack &a_rStack)
{
	m_uiSize = a_rStack.m_uiSize;
	m_iTop = a_rStack.m_iTop;
	m_uiGrowSize = a_rStack.m_uiGrowSize;

	if (a_rStack.m_paData/* not zero */)
	{
		// allocate memory and set all values to 0
		m_paData = new T[m_uiSize];
		memcpy(m_paData, a_rStack.m_paData, sizeof(T)* m_uiSize);
	}
	
}
template<class T> Stack<T>::~Stack(void) {
	// If dynamic memory was allocated, 
	// delete it and set pointer to NULL
	if (m_paData != NULL) {
		delete[] m_paData;
		m_paData = NULL;
	}
}
template<class T> bool Stack<T>::isEmpty() const
{
	return m_iTop < 0;
}
template<class T>
int Stack<T>::getSize() const {
	return m_iTop + 1;
}
template<class T>
void Stack<T>::push(T &a_rValue) {
	// check for space in the stack,
	if (m_uiSize <= m_iTop + 1)
	{
		// resize dynamic array if necessary
		unsigned int newSize = m_uiSize + m_uiGrowSize;
		T* newData = new T[newSize];
		memset(newData, 0, sizeof(T)* newSize);
		memcpy(newData, m_paData, sizeof(T)*m_uiSize);
		delete m_paData;
		m_paData = newData;
		m_uiSize = newSize;
	}

	// add value to back of stack
	m_iTop++;
	m_paData[m_iTop] = a_rValue;
}
template<class T>
const T& Stack<T>::pop() {
	// remove value from back of stack
	if (!isEmpty())
	{
		return m_paData[m_iTop--];
	}
}
template<class T>
const T& Stack<T>::top() 
{
	// return value from back of stack
	return m_paData[m_iTop];
}
template<class T>
void Stack<T>::draw(void(*drawCallback)(const T*)) {
	// since the template doesn't know how to draw 
	// the template type use a callback function to
	// draw the elements in our stack
	T* pEnd = m_paData + m_iTop;
	for (T* p = pEnd; p > m_paData; --p) {
		drawCallback(p);
	}
}