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
	int first=INT_MIN;
	int index=-1;
	int second=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>first)
		{
			second=first;
			first=a[i];
			index=i;
		}
		else if(a[i]>=second && i!=index)
		{
			second=a[i];
		}
	}
	cout<<first*second<<endl;
}
