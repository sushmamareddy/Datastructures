#include<bits/stdc++.h>
using namespace std;
vector<int> subarray(int a[],int n)
{
	
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
	vector<int>v=subarray(a,n);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\n";
	}
}
