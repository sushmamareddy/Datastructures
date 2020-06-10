#include<bits/stdc++.h>
using namespace std;
int maximum(int a[],int n)
{
	unordered_map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]++;
	}
	int maxnum=0;
	int num=0;
	for(int i=0;i<n;i++)
	{
		if(m[a[i]]>maxnum)
		{
			maxnum=m[a[i]];
			num=a[i];
		}
	}
	return num;
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
	int ans=maximum(a,n);
	cout<<ans<<"\n";
}
