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
		Node *newNode =new Node(data);
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
Node *deletenode(Node *head)
{
	Node *temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	Node *a=temp;
	temp=temp->next;
	a->next=NULL;
	delete temp;
	return head;
}
int main()
{
	Node *head=input();
	print(head);
	cout<<endl;
	head=deletenode(head);
	print(head);
}
