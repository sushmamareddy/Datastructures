#include<bits/stdc++.h>
using namespace std;
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
BinaryTree<int> *input()
{
	int rootdata;
	cout<<"enter data : "<<endl;
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryTree<int>*root=new BinaryTree<int>(rootdata);
	BinaryTree<int>*leftc=input();
	BinaryTree<int>*rightc=input();
	root->left=leftc;
	root->right=rightc;
	return root;
}
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
	BinaryTree<int>*root=input();
	print(root);
}
