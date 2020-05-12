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
	int d;
	cout<<"enter data : \n";
	cin>>d;
	TreeNode<int>* root=new TreeNode<int>(d);
	cout<<"enter no of children of "<<d<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		TreeNode<int>*child=input();
		root->children.push_back(child);
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
		cout<<root->children[i]->data<<",";
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
