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
int findnode(Node *head,int element)
{
	int i=0;
	while(head!=NULL)
	{
		if(head->data==element)
		{
			return i;
		}
		head=head->next;
		i++;
	}
	return -1;
}
int main()
{
	Node *head=input();
	cout<<"enter the element you wanna find  : "<<endl;
	int element;
	cin>>element;
	int ans=findnode(head,element);
	cout<<ans<<endl;
}
