#include<iostream>//CirQue Link

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;

typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

typedef struct QNode	/* 结点结构 */
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct			/* 队列的链表结构 */
{
	QueuePtr  rear; /* 队尾指针 */
	int length;//队列长度
}LinkQueue;



/* 构造一个空队列Q */
Status InitQueue(LinkQueue *Q)
{
	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->rear->next = Q->rear;
	return OK;
}





/* 若Q为空队列,则返回TRUE,否则返回FALSE */
const Status QueueEmpty(LinkQueue& Q)
{
	//if (Q.rear->next == Q.rear)
	//	return OK;
	//else
	//	return ERROR;
	return Q.rear->next == Q.rear;
}

/* 求队列的长度 */
int QueueLength(LinkQueue Q)
{
	return Q.length;
}



/* 插入元素e为Q的新的队尾元素 */
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s) /* 存储分配失败 */
		exit(OVERFLOW);
	s->data = e;
	s->next = Q->rear->next;
	Q->rear->next = s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中① */
	Q->rear = s;		/* 把当前的s设置为队尾结点，rear指向s，见图中② */
	return OK;
}

/* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (QueueEmpty(*Q))
		return ERROR;
	p = Q->rear->next->next;		//循环链表队列队尾指针下一结点(也即头结点)的下一结点(即队头指针)
	*e = p->data;				/* 将欲删除的队头结点的值赋值给e */
	Q->rear->next->next = p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中② */
	if (p==Q->rear)
	{
		Q->rear = Q->rear->next;
		Q->rear->next == Q->rear;
	}
	free(p);
	return OK;
}

int main()
{
	LinkQueue LQ;
	int En_length=0, Pop_length=0;
	std::cin >> En_length >> Pop_length;//第一行为两个整数n和m，n表示入队序列A的长度（n个数依次连续入队，中间没有出队的情况），m表示出队序列B的元素数量（m个数依次连续出队，中间没有入队的情况）
	while (En_length&&Pop_length)
	{
		InitQueue(&LQ);
		QElemType *DATA = new QElemType[En_length];
		for (int i = 0; i < En_length; i++)
		{
			std::cin >> DATA[i];
			EnQueue(&LQ, DATA[i]);
		}
		QElemType tmp = 0;
		for (int i = 0; i < Pop_length; i++)
		{
			DeQueue(&LQ, &tmp);
			std::cout << tmp << " ";
		}
		if (QueueEmpty(LQ))
		{
			std::cout<< ERROR<<std::endl;
		}
		else
		{
			std::cout << OK << std::endl;
		}

		std::cin >> En_length >> Pop_length;
	}
	return 0;
}