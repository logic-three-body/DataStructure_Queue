#include"Circular_Queue.h"

int main()
{
	Circular_Queue test;
	QElemType tmp;
	for (int i = 0; i < MAXSIZE - 1; ++i)
		test.EnQueue(i);
	for (int i = 0; i < MAXSIZE; ++i)
	{
		test.DeQueue(tmp);
		std::cout << tmp << "\t";
		test.EnQueue(tmp + 1000);
	}
	int len = test.QueueLength();
	test.GetHead(tmp);
	test.QueueEmpty();
	test.QueueFull();
	test.QueueTraverse();
	test.ClearQueue();
	test.GetHead(tmp);
	test.QueueEmpty();
	test.QueueFull();
	test.QueueTraverse();
	std::cout << std::endl;
	system("pause");
}