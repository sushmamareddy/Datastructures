#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTree
{
	public:
	int data;
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
void print(BinaryTree<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<": ";
	if(root->left!=NULL)
	{
		cout<<"L"<<root->left->data<<" ";
	}
	if(root->right!=NULL)
	{
		cout<<"R"<<root->right->data<<" ";
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}
int main()
{
	BinaryTree<int>*root=new BinaryTree<int>(1);
	BinaryTree<int>*node1=new BinaryTree<int>(2);
	BinaryTree<int>*node2=new BinaryTree<int>(3);
	root->left=node1;
	root->right=node2;
	print(root);
}
