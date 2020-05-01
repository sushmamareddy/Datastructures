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
int cycle(Node *head)
{
	Node *slow=head;
	Node *fast=head->next;
	int count=1;
	while(fast!=NULL && fast->next!=NULL)
	{
		if(slow==fast)
		{
			break;
		}
		count++;
		slow=slow->next;
		fast=fast->next->next;
	}
	return count;
}
int main()
{
	Node *head=input();
	head->next->next->next->next->next=head->next;//cycle
	int ans=cycle(head);
	cout<<ans<<endl;
}
