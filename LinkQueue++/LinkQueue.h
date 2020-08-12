#pragma once
#include"global'.h"
typedef struct QNode	/* ���ṹ */
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct			/* ���е�����ṹ */
{
	QueuePtr front, rear; /* ��ͷ����βָ�� */
}linkqueuer;

class LinkQueue
{
private:
	linkqueuer lqr;
public:
	/* ����һ���ն���Q */
	LinkQueue();
	/* ���ٶ���Q */
	Status DestroyQueue();
	/*�жϿն���*/
	bool QueueEmpty();
	/* ��Q��Ϊ�ն��� */
	Status ClearQueue();
	/* ����еĳ��� */
	int QueueLength();
	/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
	Status GetHead( QElemType &);
	/* ����Ԫ��eΪQ���µĶ�βԪ�� */
	Status EnQueue(QElemType );
	/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
	Status DeQueue(QElemType &);
	/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
	Status QueueTraverse(LinkQueue );
};

