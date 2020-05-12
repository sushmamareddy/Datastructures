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
	cout<<"enter root data : "<<endl;
	int rootdata;
	cin>>rootdata;
	queue<TreeNode<int>*>q;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>* front=q.front();
		q.pop();
		cout<<"enter no of children of "<<front->data<<endl;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int childdata;
			cout<<"enter the "<<i+1<<" child of "<<front->data<<endl;
			cin>>childdata;
			TreeNode<int>*child=new TreeNode<int>(childdata);
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}
void print(TreeNode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" : ";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<" , ";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		print(root->children[i]);
	}
}
int main()
{
	TreeNode<int>*root=input();
	print(root);
}
