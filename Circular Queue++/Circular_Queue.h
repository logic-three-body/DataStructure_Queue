#pragma once
#include"global.h"

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
public:
	/* ��ʼ��һ���ն���Q */
	Circular_Queue();
	/* ��Q��Ϊ�ն��� */
	Status ClearQueue();
	/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
	bool QueueEmpty();
	/* ������QΪ������,�򷵻�TRUE,���򷵻�FALSE */
	bool QueueFull();
	/* ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���� */
	int QueueLength();
	/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
	Status GetHead(QElemType &);
	/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
	Status EnQueue( QElemType );
	/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
	Status DeQueue(QElemType &);
	/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
	Status QueueTraverse();
};


