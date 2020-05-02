#include<bits/stdc++.h>
using namespace std;
void stock(int *a,int n)
{
	stack<int>s;
	int *ans=new int[n];
	ans[0]=1;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(!s.empty() && a[s.top()]<a[i])
		{
			s.pop();
		}
		ans[i]=(s.empty())?i+1:(i-s.top());
		s.push(i);
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
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
	stock(a,n);
}
