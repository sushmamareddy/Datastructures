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
Node *deleten(Node *head,int m,int n)
{
	Node *t1=head;
	Node *t2=head;
	int c1=1;
	int c2=1;
	if(m==0)
	{
		return NULL;
	}
	if(n==0)
	{
		return head;
	}
	while(t1!=NULL && t2!=NULL)
	{
		while(t1!=NULL && c1<m)
		{
			t1=t1->next;
			c1++;
		}
		if(t1==NULL)
		{
			break;
		}
		t2=t1->next;
		while(t2!=NULL && c2<=n)
		{
			Node *p=t2;
			t2=t2->next;
			delete p;
			c2++;
		}
		t1->next=t2;
		t1=t2;
		c1=1;
		c2=1;
	}
	return head;
}
int main()
{
	Node *head=input();
	cout<<"enter m,n"<<endl;
	int m,n;
	cin>>m>>n;
	cout<<endl;
	head=deleten(head,m,n);
	print(head);
}
