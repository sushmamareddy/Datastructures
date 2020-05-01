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
Node *input()
{
	Node *head=NULL;
	Node *tail=NULL;
	int data;
	cin>>data;
	while(data!=-1)
	{
		Node *newnode=new Node(data);
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else
		{
			tail->next=newnode;
			tail=tail->next;
		}
		cin>>data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
Node *evenafterodd(Node *head)
{
	Node *oddt=NULL;
	Node *oddh=NULL;
	Node *event=NULL;
	Node *evenh=NULL;
	Node *temp=head;
	if(temp==NULL || temp->next==NULL)
	{
		return head;
	}
	while(temp!=NULL)
	{
		if(temp->data%2==0)
		{
			if(event==NULL)
			{
				event=temp;
				evenh=temp;
			}
			else
			{
				event->next=temp;
				event=temp;
			}
		}
		else
		{
			if(oddt==NULL)
			{
				oddh=temp;
				oddt=temp;
			}
			else
			{
				oddt->next=temp;
				oddt=temp;
			}
		}
		temp=temp->next;
	}
	if(oddh!=NULL)
	{
		oddt->next=evenh;
		if(evenh!=NULL)
		{
			event->next=NULL;
		}
		return oddh;
	}
	else
	{
		event->next=NULL;
		return evenh;
	}
}
int main()
{
	Node *head=input();
	head=evenafterodd(head);
	print(head);
}
