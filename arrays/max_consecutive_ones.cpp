#include<bits/stdc++.h>
using namespace std;
int consecutive(int a[],int n)
{
	int curcount=0;
	int maxcount=0;
	int i=0;
	int j=0;
	while(i<=j && j<n && i<n)
	{
		if(a[i]==1 && a[j]==a[i])
		{
			j++;
			curcount++;
		}
		else
		{
			if(curcount>maxcount)
			{
				maxcount=curcount;
			}
			curcount=0;
			j++;
			i=j;
		}
	}
	if(curcount>maxcount)
	{
		maxcount=curcount;
	}
	return maxcount;
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
	int ans=consecutive(a,n);
	cout<<ans<<"\n";
}
