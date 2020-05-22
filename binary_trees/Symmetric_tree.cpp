/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

*/
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
bool symmetric(BinaryTree<int>*l,BinaryTree<int>*r)
{
	if(l==NULL && r==NULL)
	{
		return true;
	}
	if(l==NULL || r==NULL)
	{
		return false;
	}
	return (l->data==r->data) && symmetric(l->right,r->left) && symmetric(l->left,r->right);
}
bool isSymmetric(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		return true;
	}
	return symmetric(root,root);
}
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
int main()
{
	BinaryTree<int>*root=input();
	bool ans=isSymmetric(root);
	if(ans)
	{
		cout<<"symmetric\n";
	}
	else
	{
		cout<<"not symmetric\n";
	}
}
