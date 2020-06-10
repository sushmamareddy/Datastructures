#include<bits/stdc++.h>
using namespace std;
void printintersection(int a1[],int a2[],int n1,int n2)
{
	unordered_map<int,int>m;
	for(int i=0;i<n1;i++)
	{
		m[a1[i]]++;
	}
	for(int i=0;i<n2;i++)
	{
		if(m[a2[i]]>0)
		{
			cout<<a2[i]<<" ";
			m[a2[i]]--;
		}
	}
}
int main()
{
	int n1;
	cin>>n1;
	int a1[n1];
	for(int i=0;i<n1;i++)
	{
		cin>>a1[i];
	}
	int n2;
	cin>>n2;
	int a2[n2];
	for(int i=0;i<n2;i++)
	{
		cin>>a2[i];
	}
	printintersection(a1,a2,n1,n2);
}
