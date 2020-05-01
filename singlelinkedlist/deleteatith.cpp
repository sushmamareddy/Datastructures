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
Node *deletenode(Node *head,int i)
{
	if(i==0){
	
	Node *temp=head;
	head=head->next;
	delete temp;
	return head;
	}
	Node *temp=head;
	int count=0;
	while(temp!=NULL && count<i-1)
	{
		count++;
		temp=temp->next;
	}
	if(temp!=NULL && temp->next!=NULL)
	{
		Node *a=temp->next;
		Node *b=a->next;
		temp->next=b;
		delete a;
	}
	return head;
}
int main()
{
	Node *head=input();
	print(head);
	cout<<endl;
	cout<<"enter the position of node u want to delete : "<<endl;
	int i;
	cin>>i;
	head=deletenode(head,i);
	print(head);
}
