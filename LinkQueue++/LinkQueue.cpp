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
	//TODO 判断空队列准确性
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
	lqr.rear->next = s;/* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中① */
	lqr.rear = s;/* 把当前的s设置为队尾结点，rear指向s，见图中② */
	return OK;
}

Status LinkQueue::DeQueue(QElemType &elem)
{
	if (QueueEmpty())
	{
		return ERROR;
	}
	QueuePtr p;
	p = lqr.front->next;/* 将欲删除的队头结点暂存给p，见图中① */
	elem = p->data;/* 将欲删除的队头结点的值赋值给e */
	lqr.front->next = p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中② */
	if (lqr.rear==p)/* 若队头就是队尾，则删除后将rear指向头结点，见图中③ */
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
