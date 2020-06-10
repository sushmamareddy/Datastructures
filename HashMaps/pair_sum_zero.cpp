#include<bits/stdc++.h>
using namespace std;
void pairsum(int a[],int n)
{
	unordered_map<int,int>m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		int key=a[i];
		if(m[key]!=0 && m.count(-key)!=0)
		{
			int times=m[key]*m[-key];
			while(times!=0)
			{
				cout<<min(key,-key)<<" ";
				cout<<max(key,-key)<<"\n";
				times--;
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
	pairsum(a,n);
}
