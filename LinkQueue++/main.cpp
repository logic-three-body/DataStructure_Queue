#pragma once
#include"LinkQueue.h"
void TestLink(LinkQueue &test, int &tmp);
void LinkTest1(LinkQueue &test);
void LinkTest2(LinkQueue &test);
int main()
{
	LinkQueue test;
	//LinkTest1(test);
	LinkTest2(test);

}

void LinkTest2(LinkQueue &test)
{
	int tmp;
	for (int i = 0; i < 3; i++)
	{
		int tmp;
		test.EnQueue(i);
	}
	//test.ClearQueue();
	TestLink(test, tmp);
	test.DestroyQueue();
	TestLink(test, tmp);
}

void LinkTest1(LinkQueue &test)
{
	for (int i = 0; i < 5; i++)
	{
		int tmp;
		test.EnQueue(i);
		TestLink(test, tmp);
	}
	for (int i = 0; i < 5; i++)
	{
		int tmp;
		test.DeQueue(tmp);
		TestLink(test, tmp);
	}
}

void TestLink(LinkQueue &test, int &tmp)
{
	std::cout << "len= " << test.QueueLength() << std::endl;
	test.QueueTraverse();
	tmp = 1000;
	test.GetHead(tmp);
	std::cout << "LinkHead is " << tmp << std::endl;
}

