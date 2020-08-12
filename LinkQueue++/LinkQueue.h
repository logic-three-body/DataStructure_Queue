#pragma once
#include"global'.h"
typedef struct QNode	/* 结点结构 */
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct			/* 队列的链表结构 */
{
	QueuePtr front, rear; /* 队头、队尾指针 */
}linkqueuer;

class LinkQueue
{
private:
	linkqueuer lqr;
public:
	/* 构造一个空队列Q */
	LinkQueue();
	/* 销毁队列Q */
	Status DestroyQueue();
	/*判断空队列*/
	bool QueueEmpty();
	/* 将Q清为空队列 */
	Status ClearQueue();
	/* 求队列的长度 */
	int QueueLength();
	/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
	Status GetHead( QElemType &);
	/* 插入元素e为Q的新的队尾元素 */
	Status EnQueue(QElemType );
	/* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
	Status DeQueue(QElemType &);
	/* 从队头到队尾依次对队列Q中每个元素输出 */
	Status QueueTraverse(LinkQueue );
};

