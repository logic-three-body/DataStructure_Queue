//Double Que
/*
�������˲�����ѭ�����е�ʵ��
���������ѭ�����е����˶����Խ��в����ɾ��������
����һ��ѭ�����У�ʵ�ִӶ�ͷ��ӣ��Ӷ�β���Ӳ������
Լ���Ӷ�ͷ���ʱ��"�±�С"�ķ���չ��
�Ӷ�β���ʱ�����±��ķ���չ��
*/

#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q)
{
	Q.base = new int[MAXSIZE];
	if (!Q.base)return 0;
	Q.front = Q.rear = 0;
	return 1;
}

int EnQueue(SqQueue &Q, int e)
{
	if (Q.rear == (Q.front - 1 + MAXSIZE) % MAXSIZE)	return 0;
	Q.base[Q.front] = e;
	Q.front = (Q.front - 1 + MAXSIZE) % MAXSIZE;
	return 1;
}

int DeQueue(SqQueue &Q, int &e)//&
{
	if (Q.front == Q.rear)	return 0;
	e = Q.base[Q.rear];
	Q.rear = (Q.rear - 1 + MAXSIZE) % MAXSIZE;
	return 1;
}

int IsEmpty(SqQueue &Q)
{
	if (Q.front == Q.rear)	return 0;
	else return 1;
}

int main()
{
	int n, m; int a = 0, b = 0;
	while (1)
	{
		cin >> n; m = n;
		if (n == 0)	break;
		SqQueue Q;
		InitQueue(Q);
		while (n != 0)
		{
			cin >> a;
			EnQueue(Q, a);
			n--;
		}
		while (m != 0)
		{
			DeQueue(Q, b);
			cout << b;
			if (m != 1)cout << " ";
			m--;
		}
		//cout<<IsEmpty(Q);
		cout << endl;
	}
}
