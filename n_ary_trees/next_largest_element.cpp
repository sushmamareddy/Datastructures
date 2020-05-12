/*
Given a generic tree and an integer n. 
Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.
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
TreeNode<int>* nextLargerElement(TreeNode<int>*root,int n)
{
	if(root==NULL)
	{
		return root;
	}
	bool flag=false;
	TreeNode<int>* nextlarger=NULL;
	if(root->data > n)
	{
		flag=true;
		nextlarger=root;
	}
	for(int i=0;i<root->children.size();i++)
	{
		TreeNode<int>*temp=nextLargerElement(root->children[i],n);
		if(nextlarger==NULL)
		{
			nextlarger=temp;
		}
		else if(temp!=NULL && temp->data < nextlarger->data)
		{
			nextlarger=temp;
			flag=true;
		}
	}
	return nextlarger;
}
int main()
{
	TreeNode<int>*root=input();
	int n;
	cout<<"enter n : ";
    cin >> n;
	TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}
