#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		Node(int data)
		{
			this->data=data;
			next=NULL;
		}
};
class Stack
{
	Node *head;
	int totalsize;
	public:
		stack()
		{
			head=NULL;
			totalsize=0;
		}
		int size()
		{
			return totalsize;
		}
		bool isEmpty()
		{
			return totalsize==0;
		}
		void push(int element)
		{
			Node *newNode=new Node(element);
			newNode->next=head;
			head=newNode;
			totalsize++;
		}
		int pop()
		{
			if(totalsize==0)
			{
				cout<<"stack is empty\n";
				return 0;
			}
			int ans=head->data;
			Node *temp=head;
			head=head->next;
			delete temp;
			totalsize--;
			return ans;
		}
		int top()
		{
			if(isEmpty())
			{
				cout<<"stack is empty\n";
				return 0;
			}
			return head->data;
		}
};
int main()
{
	Stack s;
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
