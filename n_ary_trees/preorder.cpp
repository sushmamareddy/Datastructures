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
void preorder(TreeNode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++)
	{
		preorder(root->children[i]);
	}
}
int main()
{
	TreeNode<int>*root=input();
	preorder(root);	
}
