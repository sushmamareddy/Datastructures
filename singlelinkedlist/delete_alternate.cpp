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
	int n;
	cin>>n;
	while(n!=-1)
	{
		Node *newNode=new Node(n);
		if(head==NULL)
		{
			head=newNode;
			tail=newNode;
		}
		else
		{
			tail->next=newNode;
			tail=newNode;
		}
		cin>>n;
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
void deletenode(Node *head)
{
	if (head == NULL)  
        return;  
    Node *prev = head;  
    Node *node = head->next;  
  
    while (prev != NULL && node != NULL)  
    {  
        prev->next = node->next;  
        free(node);  
        prev = prev->next;  
        if (prev != NULL)  
            node = prev->next;  
    }   
}
int main()
{
	Node *head=input();
	print(head);
	cout<<"\n";
	deletenode(head);
	print(head);
}
