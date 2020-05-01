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
Node *middle(Node *head)
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
int length(Node *head)
{
	int len=0;
	Node *temp=head;
	while(temp!=NULL)
	{
		len++;
		temp=temp->next;
	}
	return len;
}
Node *reverse(Node *h2)
{
	Node *temp=h2;
	Node *p=NULL;
	Node *c=h2;
	Node *n=h2->next;
	while(c->next!=NULL)
	{
		c->next=p;
		p=c;
		c=n;
		n=n->next;
	}
	c->next=p;
	h2=c;
	return h2;
}
bool palindrome(Node *head)
{
	Node *h1=head;
	Node *mid=middle(head);	
	int l=length(head);
	Node *n=NULL;
	Node *h2=NULL;
	n=mid->next;
	h2=n;
	mid->next=NULL;
	h2=reverse(h2);
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->data!=h2->data)
		{
			return false;
		}
		h1=h1->next;
		h2=h2->next;
	}
	return true;	
}
int main()
{
	Node *head=input();
	bool ans=palindrome(head);
	if(ans==true)
	{
		cout<<"list is palindrome"<<endl;
	}
	else
	{
		cout<<"Not palindrome"<<endl;
	}
}
