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
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
}
Node *append(Node *head,int n)
{
	if(n==0)
	{
		return head;
	}
	Node *temp=head;
	int l=0;
	while(temp!=NULL)
	{
		l++;
		temp=temp->next;
	}
	int c=l-n-1,i=0;
	temp=head;
	while(i<c and temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	Node *ne=temp->next;
	Node *ce=temp;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
	ce->next=NULL;
	head=ne;
	return head;
	
}
int main()
{
	Node *head=input();
	print(head);
	cout<<endl;
	cout<<"enter the last nvalue to append : "<<endl;
	int n;
	cin>>n;
	head=append(head,n);
	print(head);
}

