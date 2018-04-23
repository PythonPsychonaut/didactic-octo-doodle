
#include <iostream>
#include <IntQueue.h>
using namespace std;

int main()
{
	IntQueue iQueue(7);

	cout << "Enqueuing 7 items...\n";

	try
	{
		for (int k = 1; k <= 8; k++)
			iQueue.enqueue(k*k);
	}
	catch (IntQueue::OverFlow)
	{
		cout << "The queue is full.\n";
		exit(1);
	}

	cout << "The values in the quere were: ";
	while (!iQueue.isEmpty())
	{
		int value;
		iQueue.dequeue(value);
		cout << value << "  ";
	}
	cout << endl;
	return 0;
}
