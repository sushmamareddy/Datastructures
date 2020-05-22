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
void zigzagprint(BinaryTree<int>*root)
{
	stack<BinaryTree<int>*>s1,s2;
	if(root==NULL)
	{
		return;
	}
	s1.push(root);
	bool flag=1;
	while(!s1.empty() || !s2.empty())
	{
		if(flag)
		{
			if(s1.empty())
			{
				cout<<"\n";
				flag=0;
				continue;
			}
			else
			{
				BinaryTree<int>*f=s1.top();
				s1.pop();
				cout<<f->data<<" ";
				if(f->left!=NULL)
				{
					s2.push(f->left);
				}
				if(f->right!=NULL)
				{
					s2.push(f->right);
				}
			}
		}
		else
		{
			if(s2.empty())
			{
				cout<<"\n";
				flag=1;
				continue;
			}
			else
			{
				BinaryTree<int>*f=s2.top();
				s2.pop();
				cout<<f->data<<" ";
				if(f->right!=NULL)
				{
					s1.push(f->right);
				}
				if(f->left!=NULL)
				{
					s1.push(f->left);
				}
			}
		}
	}
}
int main()
{
	BinaryTree<int>*root=input();
	zigzagprint(root);
}
