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
Node *kreverse(Node *head,int n)
{
	Node *temp=head;
	Node *h=NULL;
	Node *t=NULL;
	int count=0;
	while(count<n && temp!=NULL)
	{
		h=temp->next;
		temp->next=t;
		t=temp;
		temp=h;
		count++;
	}
	if(h!=NULL)
	{
		head->next=kreverse(h,n);
	}
	return t;
}
int main()
{
	Node *head=input();
	cout<<"enter n :"<<endl;
	int n;
	cin>>n;
	head=kreverse(head,n);
	print(head);
}
