/*
In a given Generic Tree, replace each node with its depth value. 
You need to just update the data of each node, no need to return or print anything.
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
		~TreeNode()
		{
			for(int i=0;i<children.size();i++)
			{
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
	q.push(NULL);
	while(!q.empty())
	{
		TreeNode<int>*front=q.front();
		q.pop();
		if(front==NULL)
		{
			if(q.empty())
			{
				break;
			}
			else
			{
				cout<<endl;
				q.push(NULL);
				continue;
			}
		}
		cout<<front->data<<" ";
		for(int i=0;i<front->children.size();i++)
		{
			q.push(front->children[i]);
		}
	}
	
}
int main()
{
	TreeNode<int>*root=input();
	print(root);
}
