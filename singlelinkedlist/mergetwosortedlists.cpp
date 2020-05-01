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
Node *merge(Node *head1,Node *head2)
{
	Node *h=NULL;
	Node *t=NULL;
	if(head1->data < head2->data)
	{
		h=head1;
		t=head1;
		head1=head1->next;
	}
	else
	{
		h=head2;
		t=head2;
		head2=head2->next;
	}
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data < head2->data)
		{
			t->next=head1;
			t=head1;
			head1=head1->next;
		}
		else
		{
			t->next=head2;
			t=head2;
			head2=head2->next;
		}
	}
	if(head1==NULL)
	{
		t->next=head2;
	}
	if(head2==NULL)
	{
		t->next=head1;
	}
	return h;
}
int main()
{
	cout<<" input Linked-List -1 : "<<endl;
	Node *head1=input();
	cout<<endl;
	cout<<"input Linked-List-2 : "<<endl;
	Node *head2=input();
	cout<<endl;
	cout<<"linkedlist-1"<<endl;
	print(head1);
	cout<<endl;
	cout<<"linkedlist-2"<<endl;
	print(head2);
	cout<<endl;
	Node *head=merge(head1,head2);
	print(head);
}
