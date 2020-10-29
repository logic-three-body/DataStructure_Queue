//Double Que
/*
基于两端操作的循环队列的实现
如果允许在循环队列的两端都可以进行插入和删除操作。
构造一个循环队列，实现从队头入队，从队尾出队并输出。
约定从队头入队时向"下标小"的方向发展，
从队尾入队时则向下标大的方向发展。
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
