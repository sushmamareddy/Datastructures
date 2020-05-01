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
void printithnode(Node *head,int i)
{
	int l=0;
	while(head!=NULL)
	{
		if(l==i)
		{
			cout<<head->data<<endl;
			return;
		}
		l++;
		head=head->next;
	}
}
int main()
{
	Node *head=input();
	int i;
	cin>>i;
	printithnode(head,i);
	
}
