/*
Given a tree, find and return the node for which sum of data of all children and the node itself is maximum.
 In the sum, data of node itself and data of immediate children is to be taken.

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
};
template <typename T>
class Maxsum
{
  	public:
    int sum;
    TreeNode<int> *node;
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
Maxsum<int>* helper(TreeNode<int>* root)
{
    if(root==NULL)
    {
        Maxsum<int> *a=new Maxsum<int>();
        a->sum=INT_MIN;
        a->node=NULL;
        return a;
    }
    Maxsum<int> *ans=new Maxsum<int>();
    int sum1=root->data;
    ans->node=root;
    for(int i=0;i<root->children.size();i++)
    {
        sum1=sum1+root->children[i]->data;
    }
    ans->sum=sum1;
    for(int i=0;i<root->children.size();i++)
    {
        Maxsum<int>* smallans=helper(root->children[i]);
        if(smallans->sum > ans->sum)
        {
            ans->sum=smallans->sum;
            ans->node=smallans->node;
        }
    }
    return ans;
}
TreeNode<int>* maxSumNode(TreeNode<int> *root)
{
    return helper(root)->node;
}

int main()
{
	TreeNode<int>* root=input();
	TreeNode<int>*ans=maxSumNode(root);
	cout<<ans->data<<endl;
}
