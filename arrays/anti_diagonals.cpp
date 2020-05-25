/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

Input:

1 2 3
4 5 6
7 8 9
Return:

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
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
			cin>>a[i][j];
	}
	vector<vector<int>>ans;
	for(int i=0;i<=(2*(n-1));i++)
	{
		vector<int>v;
		for(int j=0;j<=i;j++)
		{
			int k=i-j;
			if(j<n && k<n)
			{
				v.push_back(a[j][k]);
			}
		}
		ans.push_back(v);
	}
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
}
