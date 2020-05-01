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
		cout<<temp->data<<" --> ";
		temp=temp->next;
	}
}
Node *duplicate(Node *head)
{
	Node *t1=head;
	Node *t2=head->next;
	while(t1!=NULL && t2!=NULL){
	if(t1->data !=t2->data)
	{
		t1->next=t2;
		t1=t1->next;
		t2=t2->next;
	}
	else
	{
		Node *a=t2;
		t2=t2->next;
		delete a;
	}
	
	}
	t1->next=t2;
	return head;
}
int main()
{
	Node *head=input();
	print(head);
	cout<<endl;
	head=duplicate(head);
	print(head);
}

