/*
Largest Sum Contiguous Subarray
Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
i/p:-2, -3, 4, -1, -2, 1, 5, -3
o/p:7
*/
#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int n)
{
	int cursum=0;
	int maxsum=0;
	for(int i=0;i<n;i++)
	{
		if(cursum<0)
		{
			cursum=0;
		}
		if(cursum>maxsum)
		{
			maxsum=cursum;
		}
		cursum=cursum+a[i];
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
