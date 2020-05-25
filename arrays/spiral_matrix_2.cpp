/*
Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

Example:

Given n = 3,

You should print the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	int r1=0;
	int r2=n-1;
	int c1=0;
	int c2=n-1;
	int count=1;
	while(count<=(n*n))
	{
		for(int j=c1;j<=c2;j++)
		{
			a[r1][j]=count;
			count++;
		}
		r1++;
		for(int i=r1;i<=r2;i++)
		{
			a[i][c2]=count;
			count++;	
		}	
		c2--;
		for(int j=c2;j>=c1;j--)
		{
			a[r2][j]=count;
			count++;
		}
		r2--;
		for(int i=r2;i>=r1;i--)
		{
			a[i][c1]=count;
			count++;
		}
		c1++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
