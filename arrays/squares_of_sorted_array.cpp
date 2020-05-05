#include<bits/stdc++.h>
using namespace std;
vector<int> square(vector<int>v)
{
	for(int i=0;i<v.size();i++)
	{
		v[i]=v[i]*v[i];
	}
	sort(v.begin(),v.end());
	return v;
}
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	v=square(v);
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
}
