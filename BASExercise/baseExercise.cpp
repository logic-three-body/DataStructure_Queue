#include<iostream>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;

typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */
/* 循环队列的顺序存储结构 */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* 头指针 */
	int rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}SqQueue;

class Circular_Queue
{
private:
	SqQueue cq;
	int tag;//判断队列是否为空
public:
	/* 初始化一个空队列Q */
	Circular_Queue();
	/* 将Q清为空队列 */
	Status ClearQueue();
	/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
	Status QueueEmpty();
	/* 若队列Q为满队列,则返回TRUE,否则返回FALSE */
	Status QueueFull();
	/* 返回Q的元素个数，也就是队列的当前长度 */
	int QueueLength();
	/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
	Status GetHead(QElemType &);
	/* 若队列未满，则插入元素e为Q新的队尾元素 */
	Status EnQueue(QElemType);
	/* 若队列不空，则删除Q中队头元素，用e返回其值 */
	Status DeQueue(QElemType &);
	Status DeQueue();
	/* 从队头到队尾依次对队列Q中每个元素输出 */
	Status QueueTraverse();
};


int main()
{
	while (true)
	{
		int num;
		std::cin >> num;
		if (!num)
		{
			break;
		}
		Circular_Queue*CQ = new Circular_Queue;
		while (num--)
		{
			QElemType elem = 0;
			std::cin >> elem;
			CQ->EnQueue(elem);
		}
		CQ->QueueTraverse();
		delete CQ;
	}
	return 0;
}


Circular_Queue::Circular_Queue()
{
	cq.front = cq.rear = 0;
}

Status Circular_Queue::ClearQueue()
{
	cq.front = cq.rear = 0;
	return OK;
}

Status Circular_Queue::QueueEmpty()
{
	if (cq.front == cq.rear)
	{
		tag = OK;
	}
	else
	{
		tag = ERROR;
	}
	return tag;
}

Status Circular_Queue::QueueFull()
{
	if (cq.rear == (cq.front - 1 + MAXSIZE) % MAXSIZE)
	{
		tag = OK;
	}
	else
	{
		tag = ERROR;
	}
	return tag;
}

int Circular_Queue::QueueLength()
{
	return (cq.rear - cq.front + MAXSIZE) % MAXSIZE;
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

Status Circular_Queue::EnQueue(QElemType elem)//从队首入并向下标小的方向发展
{
	if (QueueFull())
	{
		return ERROR;
	}
	cq.data[cq.front] = elem;
	cq.front = (cq.front - 1+MAXSIZE) % MAXSIZE;
	return OK;
}

Status Circular_Queue::DeQueue(QElemType &elem)
{
	if (QueueEmpty())
	{
		return ERROR;
	}
	elem = cq.data[cq.rear];
	cq.rear = (cq.rear - 1) % MAXSIZE;
	return OK;
}

Status Circular_Queue::DeQueue()
{
	if (QueueEmpty())
	{
		return ERROR;
	}
	cq.rear = (cq.rear - 1) % MAXSIZE;
	return OK;
}


Status Circular_Queue::QueueTraverse()
{
	int i = cq.rear;
	if (QueueEmpty())
	{
		return ERROR;
	}
	else
	{
		while ((cq.rear - i + MAXSIZE)%MAXSIZE  != cq.front)
		{
			int index = (cq.rear - i + MAXSIZE) % MAXSIZE;
			if ((cq.rear - i + MAXSIZE) % MAXSIZE == cq.front+1)
			{
				std::cout << cq.data[index];
			}
			else
			{
				std::cout << cq.data[index] << " ";
			}
			++i;
		}
		std::cout << std::endl;
	}

	return OK;
}

