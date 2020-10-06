#include<iostream>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

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

Status Circular_Queue::EnQueue(QElemType elem)//�Ӷ����벢���±�С�ķ���չ
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

