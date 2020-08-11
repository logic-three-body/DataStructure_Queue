#include "Circular_Queue.h"

Circular_Queue::Circular_Queue()
{
	cq.front = cq.rear = 0;
	
}

Status Circular_Queue::ClearQueue()
{
	cq.front = cq.rear = 0;
	return OK;
}

bool Circular_Queue::QueueEmpty()
{
	return (cq.front==cq.rear);
}

bool Circular_Queue::QueueFull()
{
	return ((cq.rear+1)%MAXSIZE==cq.front);
}

int Circular_Queue::QueueLength()
{
	return (cq.rear-cq.front+MAXSIZE)%MAXSIZE;
}

Status Circular_Queue::GetHead(QElemType & elem)
{
	if (QueueEmpty())
	{
		return ERROR;
	}
	elem = cq.data[cq.front];
	return OK;
}

Status Circular_Queue::EnQueue(QElemType elem)
{
	if (QueueFull())
	{
		return ERROR;
	}
	cq.data[cq.rear] = elem;
	cq.rear = (cq.rear + 1) % MAXSIZE;
	return OK;
}

Status Circular_Queue::DeQueue(QElemType &elem)
{
	if (QueueEmpty())
	{
		return ERROR;
	}
	elem = cq.data[cq.front];
	cq.front = (cq.front + 1) % MAXSIZE;
	return OK;
}

Status Circular_Queue::QueueTraverse()
{
	int i = cq.front;
	if (QueueEmpty())
	{
		std::cout << "©у╤сап" << std::endl;
	}
	else
	{
		while ((i + cq.front) != cq.rear)
		{
			std::cout << cq.data[i];
			i = (i + 1) % MAXSIZE;
		}
		std::cout << std::endl;
	}

	return OK;
}
