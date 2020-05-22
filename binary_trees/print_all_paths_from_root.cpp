#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
	public:
	int data;
	BinaryTreeNode<int> *right;
	BinaryTreeNode<int> *left;
	BinaryTreeNode(int data)
	{
		this->data=data;
		right=NULL;
		left=NULL;
	}
};
BinaryTreeNode<int>* input()
{
	int rootdata;
	cout<<"enter root data\n";
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
	queue<BinaryTreeNode<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		BinaryTreeNode<int>* front=q.front();
		q.pop();
		cout<<"enter left node of  : "<<front->data<<"\n";
		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1)
		{
			BinaryTreeNode<int>*leftnode=new BinaryTreeNode<int>(leftdata);
			front->left=leftnode;
			q.push(leftnode);
		}
		cout<<"enter right node of : "<<front->data<<"\n";
		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1)
		{
			BinaryTreeNode<int>*rightnode=new BinaryTreeNode<int>(rightdata);
			front->right=rightnode;
			q.push(rightnode);
		}
	}
	return root;
}
void print(BinaryTreeNode<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	queue<BinaryTreeNode<int>*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		BinaryTreeNode<int>*front=q.front();
		q.pop();
		if(front==NULL)
		{
			if(q.empty())
			{
				return;
			}
			else
			{
				q.push(NULL);
				cout<<"\n";
				continue;
			}
		}
		cout<<front->data<<" ";
		if(front->left!=NULL)
		{
			q.push(front->left);
		}
		if(front->right!=NULL)
		{
			q.push(front->right);
		}
		
	}
}
void print(int path[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<path[i]<<" ";
	}
	cout<<"\n";
}
void printpaths(BinaryTreeNode<int>*root,int path[],int len)
{
	if(root==NULL)
	{
		return;
	}
	path[len]=root->data;
	len++;
	if(root->left==NULL && root->right==NULL)
	{
		print(path,len);
	}
	else
	{
		printpaths(root->left,path,len);
		printpaths(root->right,path,len);
	}
}
void printpath(BinaryTreeNode<int>*root)
{
	int path[100000];
	printpaths(root,path,0);
}
int main()
{
	BinaryTreeNode<int>*root=input();
	print(root);
	cout<<"\n------------------------------------------------------\n";
	printpath(root);
}
