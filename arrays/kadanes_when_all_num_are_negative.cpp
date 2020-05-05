/*
Largest Sum Contiguous Subarray
Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.(all negative numbers)
i/p:-2, -3, -4, -1, -2, -1, -5, -3
o/p:-1
*/
#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int n)
{
	int cursum=a[0];
	int maxsum=a[0];
	for(int i=1;i<n;i++)
	{
		cursum=max(a[i],cursum+a[i]);
		maxsum=max(cursum,maxsum);
	}
	return maxsum;
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
	int ans=kadane(a,n);
	cout<<ans<<"\n";
}
