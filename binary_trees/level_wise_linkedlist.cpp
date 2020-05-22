#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTree
{
	public:
		int data;
		BinaryTree *left;
		BinaryTree *right;
	BinaryTree(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;	
	}	
};
template <typename T>
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
BinaryTree<int>* input()
{
	int rootdata;
	cout<<"enter root data : ";
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryTree<int>* root=new BinaryTree<int>(rootdata);
	queue<BinaryTree<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		BinaryTree<int>* front=q.front();
		q.pop();
		cout<<"enter left node of "<<front->data<<endl;
		int leftvalue;
		cin>>leftvalue;
		if(leftvalue!=-1)
		{
			BinaryTree<int>*leftnode=new BinaryTree<int>(leftvalue);
			front->left=leftnode;
			q.push(leftnode);
		}
		cout<<"enter right node of "<<front->data<<endl;
		int rightvalue;
		cin>>rightvalue;
		if(rightvalue!=-1)
		{
			BinaryTree<int>*rightnode=new BinaryTree<int>(rightvalue);
			front->right=rightnode;
			q.push(rightnode);
		}
	}
	return root;
}
vector<Node<int>*> create(BinaryTree<int>*root)
{
	queue<BinaryTree<int>*>q;
    if(root==NULL)
    {
        Node<int> *head=NULL;
        vector<Node<int>*>v;
        v.push_back(head);
        return v;
    }
    q.push(root);
    q.push(NULL);
    vector<Node<int>*>v;
    Node<int> *head=NULL;
    Node<int> *tail=NULL;
    while(!q.empty())
    {
        BinaryTree<int>*front=q.front();
        q.pop();
        if(front==NULL)
        {
            if(q.empty())
            {
                tail->next=NULL;
                v.push_back(head);
                break;
            }
            else
            {
                tail->next=NULL;
                v.push_back(head);
                head=NULL;
                tail=NULL;
                q.push(NULL);
                continue;
            }
        }
        Node<int>* n=new Node<int>(front->data);
        if(head==NULL)
        {
            head=n;
            tail=n;
        }
        else
        {
            tail->next=n;
            tail=tail->next;
        }
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
    }
    return v;
}
void print(Node<int>* head)
{
	Node<int>*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
int main()
{
	BinaryTree<int> *root=input();
	vector<Node<int>*>v=create(root);
	for(int i=0;i<v.size();i++)
	{
		print(v[i]);
	}
}
