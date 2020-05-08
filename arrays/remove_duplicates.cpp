#include<bits/stdc++.h>
using namespace std;
vector<int> remove(int a[],int n)
{
	set<int>s;
	vector<int>result;
	for(int i=0;i<n;i++)
	{
		if(s.find(a[i])==s.end())
		{
			s.insert(a[i]);
			result.push_back(a[i]);
		}
	}
	return result;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int>ans=remove(a,n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
