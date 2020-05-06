/*
You are given a non-negative number represented as an array of digits.
Example: 123 is represented as [1,2,3]
You must add 1 to the number ( increment the number represented by the digits ) and return the required array or list.
The digits are stored such that the most significant digit is at the head of the list.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> add(vector<int>a,int n)
{
	vector<int>v;
	int carry=1;
	for(int i=n-1;i>=0;i--)
	{
		int s=a[i]+carry;
		v.push_back(s%10);
		carry=s/10;
	}
	if(carry!=0)
	{
		v.push_back(carry);
	}
	vector<int>ans;
	int i=v.size()-1;
	while(i>=0)
	{
		if(v[i]!=0)
		{
			break;
		}
		i--;
	}
	while(i>=0)
	{
		ans.push_back(v[i]);
		i--;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int>ans=add(a,n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans.at(i)<<" ";
	}
	cout<<"\n";
}
