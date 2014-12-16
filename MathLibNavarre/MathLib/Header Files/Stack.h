#pragma once
template <class T>
class Stack
{
private:
	T* m_paData;
	unsigned int m_uiSize;
	int m_iTop;
	unsigned int m_uiGrowSize;
public:
	Stack(unsigned int a_uiSize, unsigned int a_uiGrowSize = 1);	Stack(const Stack &a_rStack);
	~Stack(void);

	// Accessory Functions
	bool isEmpty() const;
	int getSize() const;
	// Access Functions
	void push(T &a_rValue);
	const T& pop();
	const T& top();
	// So we can draw the stack,
	// takes a callback function
	void draw(void(*drawCallback)
		(const T*));
};

