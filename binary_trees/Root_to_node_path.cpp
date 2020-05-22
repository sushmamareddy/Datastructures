#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTree
{
	public:
		int data;
		BinaryTree<int>* left;
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
	cout<<"enter root data \n";
	int rootdata;
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
		BinaryTree<int>*front=q.front();
		q.pop();
		cout<<"enter left of "<<front->data<<"\n";
		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1)
		{
			BinaryTree<int>* leftnode=new BinaryTree<int>(leftdata);
			front->left=leftnode;
			q.push(leftnode);
		}
		cout<<"enter right of "<<front->data<<"\n";
		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1)
		{
			BinaryTree<int>* rightnode = new BinaryTree<int>(rightdata);
			front->right=rightnode;
			q.push(rightnode);
		}
	}
	return root;
}
vector<int>* path(BinaryTree<int>*root,int k)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==k)
	{
		vector<int>*a=new vector<int>();
		a->push_back(root->data);
		return a;
	}
	vector<int>*leftans=path(root->left,k);
	if(leftans!=NULL)
	{
		leftans->push_back(root->data);
		return leftans;
	}
	vector<int>*rightans=path(root->right,k);
	if(rightans!=NULL)
	{
		rightans->push_back(root->data);
		return rightans;
	}
	else
	{
		return NULL;
	}
}
int main()
{
	BinaryTree<int>*root=input();
	int k;
	cin>>k;
	vector<int>*a=path(root,k);
	for(int i=0;i<a->size();i++)
	{
		cout<<a->at(i)<<" ";
	}
	delete a;
}
