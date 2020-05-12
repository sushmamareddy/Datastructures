#include<bits/stdc++.h>
using namespace  std;
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
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>* front=q.front();
		q.pop();
		int n;
		cout<<"enter no of children of "<<front->data<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"enter "<<i+1<<" child of"<<front->data<<endl;
			int childdata;
			cin>>childdata;
			TreeNode<int>* child=new TreeNode<int>(childdata);
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}
void printdepth(TreeNode<int>* root,int d)
{
	if(root==NULL)
	{
		return;
	}
	if(d==0)
	{
		cout<<root->data<<" ";
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		printdepth(root->children[i],d-1);
	}
}
int main()
{
	TreeNode<int>*root=input();
	int d;
	cout<<"enter depth : ";
	cin>>d;
	printdepth(root,d);
}
