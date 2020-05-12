#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	TreeNode<int>*root=new TreeNode<int>(1);
	TreeNode<int>*node1=new TreeNode<int>(2);
	TreeNode<int>* node2=new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
}
