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
Node *nextnumber(Node *head)
{
	head=reverse(head);
	int carry=1;
	Node *temp=head;
	while(temp!=NULL)
	{
		int data1=temp->data+carry;
		temp->data=data1%10;
		carry=data1/10;
		temp=temp->next;
	}
	head=reverse(head);
	if(carry>0)
	{
		Node *newnode=new Node(carry);
		newnode->next=head;
		head=newnode;
	}

	return head;
}
int main()
{
	Node *head=input();
	head=nextnumber(head);
	print(head);
}
