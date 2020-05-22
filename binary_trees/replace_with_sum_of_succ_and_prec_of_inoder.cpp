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
BinaryTree<int>* input()
{
	int rootdata;
	cout<<"enter root data : "<<"\n";
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryTree<int>*root=new BinaryTree<int>(rootdata);
	queue<BinaryTree<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		BinaryTree<int>*front=q.front();
		q.pop();
		cout<<"enter left child of "<<front->data<<"\n";
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			BinaryTree<int>*leftnode=new BinaryTree<int>(leftchild);
			q.push(leftnode);
			front->left=leftnode;
		}
		cout<<"enter right child of "<<front->data<<"\n";
		int rightchild;
		cin>>rightchild;
		if(rightchild!=-1)
		{
			BinaryTree<int>*rightnode=new BinaryTree<int>(rightchild);
			q.push(rightnode);
			front->right=rightnode;
		}
	}
	return root;
}
void print(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	queue<BinaryTree<int>*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		BinaryTree<int>* front=q.front();
		q.pop();
		if(front==NULL)
		{
			if(q.empty())
			{
				return;
			}
			else
			{
				cout<<endl;
				q.push(NULL);
				continue;
			}
		}
		cout<<front->data<<" ";
		if(front->left !=NULL)
			q.push(front->left);
		if(front->right!=NULL)
			q.push(front->right);
	}
}
void inorder(BinaryTree<int>*root,vector<int>&in)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left,in);
	in.push_back(root->data);
	inorder(root->right,in);
}
void replacetree(BinaryTree<int>*root,vector<int>in,int *i)
{
	if(root==NULL)
	{
		return;
	}
	replacetree(root->left,in,i);
	root->data=in[*i-1]+in[*i+1];
	++*i;
	replacetree(root->right,in,i);
}
void replace(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	vector<int>in;
	in.push_back(0);
	inorder(root,in);
	in.push_back(0);
	int i=1;
	replacetree(root,in,&i);
	
}
int main()
{
	BinaryTree<int>*root=input();
	replace(root);
}
