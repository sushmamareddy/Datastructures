/*
Given a random integer array A of size N. 
Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2
*/
#include<bits/stdc++.h>
using namespace std;
void findpair(int a[],int n)
{
	unordered_map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		int key=a[i];
		if(m[key]!=0 && m[-key]!=0)
		{
			int times=m[key]*m[-key];
			while(times--)
			{
				cout<<min(key,-key)<<" "<<max(key,-key)<<"\n";
			}
			m[key]=0;
			m[-key]=0;
		}
	}
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
	findpair(a,n);
}
