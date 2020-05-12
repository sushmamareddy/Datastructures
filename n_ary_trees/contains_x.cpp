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
bool containsx(TreeNode<int>*root,int x)
{
	if(root==NULL)
	{
		return false;
	}
	if(root->data==x)
	{
		return true;
	}
	for(int i=0;i<root->children.size();i++)
	{
		if(containsx(root->children[i],x))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	TreeNode<int>*root=input();
	int x;
	cout<<"enter x : ";
	cin>>x;
	if(containsx(root,x))
	{
		cout<<"x exist"<<endl;
	}
	else
	{
		cout<<"x doesnot exist "<<endl;
	}
}
