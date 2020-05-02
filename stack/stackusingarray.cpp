#include<bits/stdc++.h>
using namespace std;
class Stack
{
	int *data;
	int nextindex;
	int capacity;
	public:
	Stack(int totalsize)
	{
		data=new int[totalsize];
		nextindex=0;
		capacity=totalsize;	
	}
	int size()
	{
		return nextindex;	
	}
	bool isEmpty()
	{
		return nextindex==0;
		}	
	void push(int element)
	{
		if(nextindex==capacity)
		{
			cout<<"stack is full\n";
			return;
		}
		data[nextindex]=element;
		nextindex++;
	}
	int pop()
	{
		if(isEmpty())
		{
			cout<<"stack is empty\n";
			return INT_MIN;
		}
		nextindex--;
		return data[nextindex];
	}
	int top()
	{
		if(isEmpty())
		{
			cout<<"stack is empty\n";
			return INT_MIN;
		}
		return data[nextindex-1];
	}
};
int main()
{
	Stack s(5);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
}
