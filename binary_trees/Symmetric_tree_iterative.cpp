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
bool isSymmetric(BinaryTree<int>*root)
{
	queue<BinaryTree<int>*>q;
	q.push(root);
	q.push(root);
	while(!q.empty())
	{
		BinaryTree<int>*t1=q.front();
		q.pop();
		BinaryTree<int>*t2=q.front();
		q.pop();
		if(t1==NULL && t2==NULL)
		{
			continue;
		}
		if(t1==NULL || t2==NULL)
		{
			return false;
		}
		q.push(t1->left);
		q.push(t2->right);
		q.push(t1->right);
		q.push(t2->left);
	}
	return true;
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
