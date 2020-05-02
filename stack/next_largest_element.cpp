#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int>ans(n);
	for(int i=0;i<n;i++)
	{
		ans[i]=0;
	}
	stack<int>s;
	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && s.top()<=a[i])
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
