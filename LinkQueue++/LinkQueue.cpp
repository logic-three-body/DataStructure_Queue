#include "LinkQueue.h"

LinkQueue::LinkQueue()
{
	lqr.front = lqr.rear = new QNode;
	if (!lqr.front)
		exit(OVERFLOW);
	lqr.front->next = nullptr;
}

Status LinkQueue::DestroyQueue()
{
	while (lqr.front)
	{
		lqr.rear = lqr.front->next;
		delete lqr.front;
		lqr.front = lqr.rear;
	}
	return OK;
}

bool LinkQueue::QueueEmpty()
{
	return (lqr.front==lqr.rear);
}

Status LinkQueue::ClearQueue()
{
	//TODO �жϿն���׼ȷ��
	if (QueueEmpty())
	{
		return ERROR;
	}
	QueuePtr p, q;
	lqr.rear = lqr.front;
	p = lqr.front->next;
	lqr.front->next = nullptr;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	return OK;
}

int LinkQueue::QueueLength()
{
	int len = 0;
	QueuePtr p;
	p = lqr.front;
	while (p!=lqr.rear)
	{
		++len;
		p = p->next;
	}
	return len;
}

Status LinkQueue::GetHead(QElemType & elem)
{
	if (QueueEmpty())
	{
		return ERROR;
	}
	QueuePtr p;
	p = lqr.front->next;
	elem = p->data;
	return OK;
}

Status LinkQueue::EnQueue(QElemType elem)
{
	QueuePtr s = new QNode;
	if (!s)
		exit(OVERFLOW);
	s->data = elem;
	s->next = nullptr;
	lqr.rear->next = s;/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т� */
	lqr.rear = s;/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т� */
	return OK;
}

Status LinkQueue::DeQueue(QElemType &elem)
{
	if (QueueEmpty())
	{
		return ERROR;
	}
	QueuePtr p;
	p = lqr.front->next;/* ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т� */
	elem = p->data;/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	lqr.front->next = p->next;/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� */
	if (lqr.rear==p)/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т� */
	{
		lqr.rear = lqr.front;
	}
	delete p;
	return OK;
}

Status LinkQueue::QueueTraverse(LinkQueue)
{
	QueuePtr p;
	p = lqr.front->next;
	while (p)
	{
		std::cout << p->data;
		p = p->next;
	}
	std::cout << std::endl;
	return OK;
}
