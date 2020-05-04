#include<bits/stdc++.h>
using namespace std;
class Queue
{
	public:
	int *data;
	int capacity;
	int rear,front;
	Queue(int capacity)
	{
		this->capacity=capacity;
		data=new int[capacity];
		rear=0;
		front=0;
	}
	int getsize()
	{
		return rear;	
	}
	bool isEmpty()
	{
		if(rear==front)
		{
			return true;
		}
		return false;
	}
	void enqueue(int d)
	{
		if(capacity==rear)
		{
			cout<<"queue is full\n";
			return;
		}
		else
		{
			data[rear]=d;
			rear++;
		}
		
	}
	void dequeue()
	{
		if(rear==front)
		{
			cout<<"empty!!\n";
			return ;
		}
		int a=data[front];
		for(int i=0;i<rear-1;i++)
		{
			data[i]=data[i+1];
		}
		rear--;
	}
	int peek()
	{
		if(rear==front)
		{
			cout<<"empty!!\n";
			return -1;
		}
		return data[front];
	}
	void printqueue()
	{
		if(rear==front)
		{
			cout<<"empty!!\n";
			return ;
		}
		for(int i=front;i<rear;i++)
		{
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}	
};
int main()
{
	Queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.printqueue();
	cout<<q.getsize()<<endl;
	q.dequeue();
	q.printqueue();
	cout<<q.getsize()<<endl;
	q.dequeue();
	q.printqueue();
	cout<<q.getsize()<<endl;
	q.dequeue();
	q.printqueue();
	cout<<q.getsize()<<endl;
	q.dequeue();
	q.printqueue();
	cout<<q.getsize()<<endl;
	q.dequeue();
	q.printqueue();
	cout<<q.getsize()<<endl;
	q.dequeue();
	q.printqueue();
	cout<<q.getsize()<<endl;
}
