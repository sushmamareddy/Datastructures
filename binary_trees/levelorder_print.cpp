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
void levelorder(BinaryTree<int>*root)
{
	queue<BinaryTree<int>*>q;
	if(root==NULL)
	{
		return;
	}
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		BinaryTree<int>*front=q.front();
		q.pop();
		if(front==NULL)
		{
			if(q.empty())
			{
				break;
			}
			else
			{
				cout<<endl;
				q.push(NULL);
				continue;
			}
		}
		cout<<front->data<<" ";
		if(front->left!=NULL){
		q.push(front->left);
		}
		if(front->right!=NULL)
			q.push(front->right);		
	}
}
int main()
{
	BinaryTree<int>*root=input();
	levelorder(root);
}
