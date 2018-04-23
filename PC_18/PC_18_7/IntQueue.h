#ifndef INTQUEUE_H
#define INTQUEUE_H
#include <iostream>
using namespace std;

class IntQueue
{
private:
	int *queueArray;
	int queueSize;
	int front;
	int rear;
	int numItems;
	bool isFull();
public:
	IntQueue(int);
	~IntQueue();
	void enqueue(int);
	void dequeue(int &);
	bool isEmpty();
	void clear();
	class OverFlow{};
	class UnderFlow{};
};
#endif
