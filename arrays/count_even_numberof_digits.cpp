#include<bits/stdc++.h>
using namespace std;
int even(int a[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		int n1=(int)log10(a[i])+1;
		if(n1%2==0)
		{
			count++;
		}
	}
	return count;
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
	int ans=even(a,n);
	cout<<ans<<"\n";
}
