#pragma once
#include"global.h"

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
public:
	/* 初始化一个空队列Q */
	Circular_Queue();
	/* 将Q清为空队列 */
	Status ClearQueue();
	/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
	bool QueueEmpty();
	/* 若队列Q为满队列,则返回TRUE,否则返回FALSE */
	bool QueueFull();
	/* 返回Q的元素个数，也就是队列的当前长度 */
	int QueueLength();
	/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
	Status GetHead(QElemType &);
	/* 若队列未满，则插入元素e为Q新的队尾元素 */
	Status EnQueue( QElemType );
	/* 若队列不空，则删除Q中队头元素，用e返回其值 */
	Status DeQueue(QElemType &);
	/* 从队头到队尾依次对队列Q中每个元素输出 */
	Status QueueTraverse();
};


