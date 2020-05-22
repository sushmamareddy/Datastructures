#include<bits/stdc++.h>
using namespace std;
template<typename T>
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
class PairAns
{
	public:
		int min;
		int max;
};
BinaryTree<int> *input()
{
	int rootdata;
	cout<<"enter root data : "<<"\n";
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryTree<int> *root=new BinaryTree<int>(rootdata);
	queue<BinaryTree<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		BinaryTree<int>* front=q.front();
		q.pop();
		cout<<"enter left child of "<<front->data<<"\n";
		int leftchild;
		cin>>leftchild;
		if(leftchild !=-1)
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
PairAns minMax(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		PairAns p;
		p.min=INT_MAX;
		p.max=INT_MIN;
		return p;
	}
	PairAns leftans=minMax(root->left);
    PairAns rightans=minMax(root->right);
    int leftmin=leftans.min;
    int leftmax=leftans.max;
    int rightmin=rightans.min;
    int rightmax=rightans.max;
    int minimum=min(leftmin,min(rightmin,root->data));
    int maximum=max(leftmax,max(rightmax,root->data));
    PairAns p;
    p.min=minimum;
    p.max=maximum;
    return p;
}
int main()
{
	BinaryTree<int>*root=input();
	PairAns ans=minMax(root);
	cout<<"min : "<<ans.min<<"\n";
	cout<<"max : "<<ans.max<<"\n";
}
