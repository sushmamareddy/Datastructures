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
int find(Node *head,int n)
{
	int c=0;
	Node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data == n)
		{
			c++;
		}
		temp=temp->next;
	}
	return c;
}
int main()
{
	Node *head=input();
	cout<<"enter the key : "<<endl;
	int n;
	cin>>n;
	int ans=find(head,n);
	cout<<ans<<endl;
}
