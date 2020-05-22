/*
Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1.
 Return true if given binary tree is balanced, false otherwise.
 */
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTree
{
	public:
		int data;
		BinaryTree<int>*left;
		BinaryTree<int>*right;
		BinaryTree(int data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
};
BinaryTree<int>* input()
{
	queue<BinaryTree<int>*>q;
	int rootdata;
	cout<<"enter root data : ";
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryTree<int>*root=new BinaryTree<int>(rootdata);
	q.push(root);
	while(!q.empty())
	{
		BinaryTree<int>*front=q.front();
		q.pop();
		cout<<"enter left node of "<<front->data<<"\n";
		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1)
		{
			BinaryTree<int>*leftnode=new BinaryTree<int>(leftdata);
			front->left=leftnode;
			q.push(leftnode);
		}
		cout<<"enter right node of "<<front->data<<"\n";
		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1)
		{
			BinaryTree<int>*rightnode=new BinaryTree<int>(rightdata);
			front->right=rightnode;
			q.push(rightnode);
		}
	}
	return root;	
}
void print(BinaryTree<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	queue<BinaryTree<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		BinaryTree<int>*front=q.front();
		q.pop();
		cout<<front->data<<" : ";
		if(front->left!=NULL)
		{
			q.push(front->left);
			cout<<"L:"<<front->left->data;
			cout<<",";
		}
		else if(front->left==NULL)
		{
			cout<<"L: -1";
			cout<<",";
		}
		if(front->right!=NULL)
		{
			q.push(front->right);
			cout<<"R:"<<front->right->data;
		}
		else if(front->right==NULL)
		{
			cout<<"R:-1";
		}
		cout<<endl;
	}
}
BinaryTree<int>* removeleaf(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->left==NULL && root->right==NULL)
	{
		return NULL;
	}
	root->left=removeleaf(root->left);
	root->right=removeleaf(root->right);
	return root;
}
int main()
{
	BinaryTree<int>*root=input();
	print(root);
	cout<<"\n";
	cout<<"--------------------------------------------------------------------------------------------\n";
	root=removeleaf(root);
	print(root);
}
