
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
TreeNode<int>* secondlargest(TreeNode<int>*root)
{
	TreeNode<int>*first=NULL;
	int f=INT_MIN;
	TreeNode<int>*second=NULL;
	int s=INT_MIN;
	queue<TreeNode<int>*>q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>*front=q.front();
		q.pop();
		if(front->data > f)
		{
			s=f;
			second=first;
			f=front->data;
			first=front;
			
		}
		else if(front->data > s && front->data!=f)
		{
			s=front->data;
			second=front;
		}
		for(int i=0;i<front->children.size();i++)
		{
			q.push(front->children[i]);
		}
	}
	return second;
}
int main()
{
	TreeNode<int>*root=input();
	TreeNode<int>* ans = secondlargest(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}
