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
};
TreeNode<int>* input()
{
	int rootdata;
	cout<<"enter root data : "<<"\n";
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
void print(TreeNode<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	queue<TreeNode<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>*front=q.front();
		q.pop();
		cout<<front->data<<" : ";
		for(int i=0;i<front->children.size();i++)
		{
			q.push(front->children[i]);
			cout<<front->children[i]->data<<" , ";
		}
		cout<<endl;
	}
}
int height(TreeNode<int>*root)
{
	int h=0;
	for(int i=0;i<root->children.size();i++)
	{
		if(h<height(root->children[i]))
		{
			h=height(root->children[i]);
		}
	}
	return h+1;
}
int main()
{
	TreeNode<int>*root=input();
	cout<<"height : "<<height(root)<<endl;
}
