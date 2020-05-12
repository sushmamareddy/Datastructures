/*
Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.

*/
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
		~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
	
};
TreeNode<int>* input()
{
	int rootdata;
	cout<<"enter root data : "<<endl;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>* front=q.front();
		q.pop();
		cout<<"enter children of "<<front->data<<" \n";
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int childdata;
			cout<<"enter "<<i+1<<" child of "<<front->data<<endl;
			cin>>childdata;
			TreeNode<int>*child=new TreeNode<int>(childdata);
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}
void print(TreeNode<int>*root)
{
	queue<TreeNode<int>*>q;
	if(root==NULL)
	{
		return;
	}
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>*front=q.front();
		q.pop();
		cout<<front->data<<" : ";
		for(int i=0;i<front->children.size();i++)
		{
			q.push(front->children[i]);
			cout<<front->children[i]->data;
			if(i!=front->children.size()-1)
			{
				cout<<" , ";
			}
		}
		cout<<endl;
	}
	
}
bool identical(TreeNode<int>*root1,TreeNode<int>*root2)
{
	if(root1==NULL && root2==NULL)
	{
		return true;
	}
	if((root1==NULL && root2!=NULL ) || (root1!=NULL && root2==NULL))
	{
		return false;
	}
	if(root1->data!=root2->data)
	{
		return false;
	}
	if(root1->children.size() != root2->children.size())
	{
		return false;
	}
	for(int i=0;i<root1->children.size();i++)
	{
		if(identical(root1->children[i],root2->children[i]))
		{
			
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cout<<"tree 1 : "<<endl;
	TreeNode<int>*root1=input();
	cout<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"tree 2 : "<<endl;
	TreeNode<int>*root2=input();
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	if(identical(root1,root2))
	{
		cout<<"trees are identical \n";
	}
	else
	{
		cout<<"trees are not identical \n";
	}
}
