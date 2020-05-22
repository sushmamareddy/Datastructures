#include<bits/stdc++.h>
using namespace std;
int preindex=0;
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
	cout<<"enter root data : "<<"\n";
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryTree<int>*root=new BinaryTree<int>(rootdata);
	queue<BinaryTree<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		BinaryTree<int>*front=q.front();
		q.pop();
		cout<<"enter left child of "<<front->data<<"\n";
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1)
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
void print(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	queue<BinaryTree<int>*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		BinaryTree<int>* front=q.front();
		q.pop();
		if(front==NULL)
		{
			if(q.empty())
			{
				return;
			}
			else
			{
				cout<<endl;
				q.push(NULL);
				continue;
			}
		}
		cout<<front->data<<" ";
		if(front->left !=NULL)
			q.push(front->left);
		if(front->right!=NULL)
			q.push(front->right);
	}
}
void inorder(BinaryTree<int>*root,vector<int>&in)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left,in);
	in.push_back(root->data);
	inorder(root->right,in);
}
void preorder(BinaryTree<int>*root,vector<int>&pre)
{
	if(root==NULL)
	{
		return;
	}
	pre.push_back(root->data);
	preorder(root->left,pre);
	preorder(root->right,pre);
}
int search(vector<int>in,int start,int end,int data)
{
	int i = 0;  
    for (i = start; i < end; i++)  
    {  
        if (in[i] == data)  
        {  
            return i;  
        }  
    }  
    return i;  
}
void postorder(vector<int>in,vector<int>pre,int start,int end)
{
	if(start>end)
	{
		return;
	}
	int index=search(in,start,end,pre[preindex++]);
	postorder(in,pre,start,index-1);
	postorder(in,pre,index+1,end);
	cout<<in[index]<<" ";
}
int main()
{
	BinaryTree<int>*root=input();
	vector<int>in,pre,post;
	inorder(root,in);
	preorder(root,pre);
	for(int i=0;i<in.size();i++)
	{
		cout<<in[i]<<" ";
	}
	cout<<"\n";
	for(int i=0;i<pre.size();i++)
	{
		cout<<pre[i]<<" ";
	}
	cout<<"\n";
	postorder(in,pre,0,pre.size()-1);
}
