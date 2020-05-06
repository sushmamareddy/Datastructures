/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.
If such an integer is found return 1 else return -1.

INPUT(s):
4 -9 8 5 -1 7 5 3 

OUTPUT(s):
1
INPUT(s):
-6 -1 4 

OUTPUT(s):
-1
INPUT(s):
1 1 1 

OUTPUT(s):
-1
*/
#include<bits/stdc++.h>
using namespace std;
int nobel(int a[],int n)
{
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(i<n-1 && a[i]==a[i+1])
		{
			continue;
		}
		if((n-i-1)==a[i])
		{
			return 1;
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
	int ans=nobel(a,n);
	cout<<ans<<"\n";
}
