#include<iostream>//CirQue Link

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;

typedef int QElemType; /* QElemType���͸���ʵ������������������Ϊint */

typedef struct QNode	/* ���ṹ */
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct			/* ���е�����ṹ */
{
	QueuePtr  rear; /* ��βָ�� */
	int length;//���г���
}LinkQueue;



/* ����һ���ն���Q */
Status InitQueue(LinkQueue *Q)
{
	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->rear->next = Q->rear;
	return OK;
}





/* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
const Status QueueEmpty(LinkQueue& Q)
{
	//if (Q.rear->next == Q.rear)
	//	return OK;
	//else
	//	return ERROR;
	return Q.rear->next == Q.rear;
}

/* ����еĳ��� */
int QueueLength(LinkQueue Q)
{
	return Q.length;
}



/* ����Ԫ��eΪQ���µĶ�βԪ�� */
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s) /* �洢����ʧ�� */
		exit(OVERFLOW);
	s->data = e;
	s->next = Q->rear->next;
	Q->rear->next = s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т� */
	Q->rear = s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т� */
	return OK;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (QueueEmpty(*Q))
		return ERROR;
	p = Q->rear->next->next;		//ѭ��������ж�βָ����һ���(Ҳ��ͷ���)����һ���(����ͷָ��)
	*e = p->data;				/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->rear->next->next = p->next;/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� */
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
	std::cin >> En_length >> Pop_length;//��һ��Ϊ��������n��m��n��ʾ�������A�ĳ��ȣ�n��������������ӣ��м�û�г��ӵ��������m��ʾ��������B��Ԫ��������m���������������ӣ��м�û����ӵ������
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