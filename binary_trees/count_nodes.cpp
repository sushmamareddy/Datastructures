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
int count(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		return 0;
	}
	int c1=count(root->left);
	int c2=count(root->right);
	return c1+c2+1;
}
int main()
{
	BinaryTree<int>*root=input();	
	int ans=count(root);
	cout<<ans<<endl;
}
