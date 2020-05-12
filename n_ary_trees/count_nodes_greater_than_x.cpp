#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
	public:
		int data;
		vector<TreeNode<int>*>children;
		TreeNode(int data)
		{
			this->data=data;
		}
		~TreeNode()
		{
			for(int i=0;i<children.size();i++)
			{
				delete children[i];
			}
		}
};
TreeNode<int>* input()
{
	cout<<"enter root data  : "<<endl;
	int rootdata;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>* front=q.front();
		q.pop();
		int n;
		cout<<"enter no of children of "<<front->data<<"\n";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int childdata;
			cout<<"enter "<<i+1<<" child of "<<front->data<<"\n";
			cin>>childdata;
			TreeNode<int>*child=new TreeNode<int>(childdata);
			q.push(child);
			front->children.push_back(child);
		}
	}
	return root;
}
int count(TreeNode<int>*root,int x)
{
	int c=0;
	if(root==NULL)
	{
		return 0;
	}
	if(root->data > x)
	{
		return 1;
	}
	for(int i=0;i<root->children.size();i++)
	{
		c=c+count(root->children[i],x);
	}
	return c;
}
int main()
{
	TreeNode<int>*root=input();
	int x;
	cout<<"enter x : ";
	cin>>x;
	cout<<count(root,x);
}
