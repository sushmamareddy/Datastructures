#include<bits/stdc++.h>
using namespace std;
void subarray(int a[],int n,vector<int>&v)
{
	int cursum=0,maxsum=0;
	int curlength=0,maxlength=0,curstart=0,maxstart=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			if((cursum>maxsum) || ((cursum==maxsum) && (curlength>maxlength)))
			{
				maxsum=cursum;
				maxlength=curlength;
				maxstart=curstart;
			}
			cursum=0;
			curlength=0;
			curstart=i+1;
		}
		else
		{
			cursum=cursum+a[i];
			curlength++;
		}
	}
	if((cursum>maxsum) || ((cursum==maxsum) && (curlength>maxlength)))
	{
		maxsum=cursum;
		maxlength=curlength;
		maxstart=curstart;
	}
	for(int i=maxstart;i<=maxstart+maxlength-1;i++)
	{
		v.push_back(a[i]);
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
	vector<int>v;
	subarray(a,n,v);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\n";
	}
}
