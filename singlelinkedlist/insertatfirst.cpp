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
Node *insert(Node *head,int d)
{
	Node *newNode=new Node(d);
	newNode->next=head;
	head=newNode;
	return head;
}
int main()
{
	Node *head=input();
	print(head);
	cout<<endl;
	cout<<"enter element that u wanna place at 0th index of linked list : "<<endl;
	int d;
	cin>>d;
	head=insert(head,d);
	print(head);
}
