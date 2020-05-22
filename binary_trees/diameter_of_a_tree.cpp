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
pair<int,int> heightdiameter(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		pair<int,int>p;
		p.first=0;
		p.second=0;
		return p;
	}
	pair<int,int>lp=heightdiameter(root->left);
	pair<int,int>rp=heightdiameter(root->right);
	int lh=lp.first;
	int ld=lp.second;
	int rh=rp.first;
	int rd=rp.second;
	int height=1+max(lh,rh);
	int diameter=max(lh+rh,max(ld,rd));
	pair<int,int>p;
	p.first=height;
	p.second=diameter;
	return p;
}
int main()
{
	BinaryTree<int>*root=input();
	pair<int,int>ans=heightdiameter(root);
	cout<<"height : "<<ans.first<<"\n";
	cout<<"diameter : "<<ans.second<<"\n";
}
