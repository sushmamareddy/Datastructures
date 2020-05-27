/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 = i, j = N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]
 
f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5
 
So, we return 5.
*/
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
	int max1=INT_MIN;
	int max2=INT_MIN;
	int min1=INT_MAX;
	int min2=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int temp1=a[i]+i;
		int temp2=a[i]-i;
		if(temp1>max1)
		{
			max1=temp1;
		}
		if(temp1<min1)
		{
			min1=temp1;
		}
		if(temp2>max2)
		{
			max2=temp2;
		}
		if(temp2<min2)
		{
			min2=temp2;
		}
	}
	int ans=max(max1-min1,max2-min2);
	cout<<ans<<"\n";
}
