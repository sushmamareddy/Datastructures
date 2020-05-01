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
Node *midpoint(Node *head)
{
	Node *slow=head;
	Node *fast=head->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
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
Node *mergesort(Node *head)
{
	Node *temp=head;
	if(temp==NULL || temp->next==NULL)
	{
		return temp;
	}
	Node *mid=midpoint(head);
	Node *left=temp;
	Node *right=mid->next;
	mid->next=NULL;
	Node *t1=mergesort(left);
	Node *t2=mergesort(right);
	Node *ans=merge(t1,t2);
	return ans;
}
int main()
{
	Node *head=input();
	head=mergesort(head);
	print(head);
}
