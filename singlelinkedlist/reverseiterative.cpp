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
	int data;
	cin>>data;
	Node *head=NULL;
	Node *tail=NULL;
	while(data!=-1)
	{
		Node *newNode=new Node(data);
		if(head==NULL)
		{
			head=newNode;
			tail=newNode;
		}
		else
		{
			tail->next=newNode;
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
Node *reverse(Node *head)
{
	Node *temp=head;
	Node *p=NULL;
	Node *c=head;
	Node *n=head->next;
	while(c->next!=NULL)
	{
		c->next=p;
		p=c;
		c=n;
		n=n->next;
	}
	c->next=p;
	head=c;
	return head;
}
int main()
{
	Node *head=input();
	print(head);
	cout<<endl;
	head=reverse(head);
	print(head);
}

