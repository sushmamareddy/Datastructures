#include<bits/stdc++.h>
using namespace std;
vector<int> removeduplicates(int a[],int n)
{
	vector<int>output;
	unordered_map<int,bool>m;
	for(int i=0;i<n;i++)
	{
		if(m.count(a[i])>0)
		{
			continue;
		}
		m[a[i]]=true;
		output.push_back(a[i]);
	}
	return output;
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
	vector<int>output=removeduplicates(a,n);
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i]<<" ";
	}
}
