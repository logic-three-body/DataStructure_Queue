#include<iostream>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 5 /* �洢�ռ��ʼ������ */

typedef int Status;

typedef int QElemType; /* QElemType���͸���ʵ������������������Ϊint */
/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* ͷָ�� */
	int rear;		/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
}SqQueue;

class Circular_Queue
{
private:
	SqQueue cq;
	int tag;//�ж϶����Ƿ�Ϊ��
public:
	/* ��ʼ��һ���ն���Q */
	Circular_Queue();
	/* ��Q��Ϊ�ն��� */
	Status ClearQueue();
	/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
	Status QueueEmpty();
	/* ������QΪ������,�򷵻�TRUE,���򷵻�FALSE */
	Status QueueFull();
	/* ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���� */
	int QueueLength();
	/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
	Status GetHead(QElemType &);
	/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
	Status EnQueue(QElemType);
	/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
	Status DeQueue(QElemType &);
	Status DeQueue();
	/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
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
	if ((cq.rear + 1) % MAXSIZE == cq.front)
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

Status Circular_Queue::DeQueue()
{
	if (QueueEmpty())
	{
		return ERROR;
	}
	cq.front = (cq.front + 1) % MAXSIZE;
	return OK;
}


Status Circular_Queue::QueueTraverse()
{
	int i = cq.front;
	if (QueueEmpty())
	{
		return ERROR;
	}
	else
	{
		while ((i + cq.front) != cq.rear)
		{
			if ((i + cq.front) == cq.rear-1)
			{
				std::cout << cq.data[i];
			}
			else
			{
				std::cout << cq.data[i] << " ";
			}
			i = (i + 1) % MAXSIZE;
		}
		std::cout << std::endl;
	}

	return OK;
}

