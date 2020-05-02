#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int ans[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	stack<int>s;
	unordered_map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]++;
	}
	s.push(a[n-1]);
	ans[n-1]=-1;
	for(int i=n-2;i>=0;i--)
	{
		while(!s.empty() && m[s.top()]<=m[a[i]])
		{
			s.pop();	
		}
		if(s.empty())
		{
			ans[i]=-1;
		}
		else
		{
			ans[i]=s.top();	
		}
		s.push(a[i]);	
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
}
