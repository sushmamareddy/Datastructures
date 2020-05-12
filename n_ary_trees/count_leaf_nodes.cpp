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
int leaf(TreeNode<int>*root)
{
	int ans=0;
	if(root == NULL)
	{
		return 0;
	}
	if(root->children.size()==0)
	{
		return 1;
	}

	for(int i=0;i<root->children.size();i++)
	{
		ans=ans+leaf(root->children[i]);
	}
	return ans;
}
int main()
{
	TreeNode<int>*root=input();
	cout<<"leaf nodes : "<<leaf(root);
}
