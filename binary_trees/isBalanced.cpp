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
class pairs
{
	public:
		int height;
		bool balance;
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
pairs balanced(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		pairs p;
		p.balance=true;
		p.height=0;
		return p;
	}
	pairs leftans=balanced(root->left);
	pairs rightans=balanced(root->right);
	int lh=leftans.height;
	int lb=leftans.balance;
	int rh=rightans.height;
	int rb=rightans.balance;
	pairs ans;
	ans.height=1+max(lh,rh);
	if(abs(lh-rh)<=1 &&(lb && rb))
	{
		ans.balance=true;
	}
	else
	{
		ans.balance=false;
	}
	return ans;
}
bool isbalanced(BinaryTree<int>*root)
{
	pairs ans=balanced(root);
	return ans.balance;
}
int main()
{
	BinaryTree<int>*root=input();
	bool ans=isbalanced(root);
	if(ans)
	{
		cout<<"balanced\n";
	}
	else
	{
		cout<<"not balanced\n";
	}
}
