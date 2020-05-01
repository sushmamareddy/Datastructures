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
Node *insert(Node *head,int d,int index)
{
	Node *newNode=new Node(d);
	int i=0;
	Node *temp=head;
	if(index==0)
	{
		newNode->next=head;
		head=newNode;
		return head;
	}
	
	while(temp!=NULL &&i!=index-1)
	{
		temp=temp->next;
		i++;
	}
	if(temp!=NULL){
		
		Node *a=temp->next;
		temp->next=newNode;
		newNode->next=a;
	}
	
	return head;
	
}
int main()
{
	Node *head=input();
	print(head);
	cout<<endl;
	int index;
	cout<<"enter the position u wanna insert : "<<endl;
	cin>>index;
	cout<<"enter element that u wanna place at " <<index<<" index of linked list : "<<endl;
	int d;
	cin>>d;
	head=insert(head,d,index);
	print(head);
}
