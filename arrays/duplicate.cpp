#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int duplicate(int *a,int n)
{
	unordered_map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]++;
	}
	unordered_map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second > 1)
		{
			return it->first;
		}
	}
	return -1;
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
	int ans=duplicate(a,n);
	cout<<ans<<endl;
}
