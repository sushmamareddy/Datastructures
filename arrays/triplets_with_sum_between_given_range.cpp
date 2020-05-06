/*
	Given an array of real numbers greater than zero in form of strings.

Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .

Return 1 for true or 0 for false.

Example:

Given

[0.6, 0.7, 0.8, 1.2, 0.4]
You should return

1
as 0.6 + 0.7 + 0.4 = 1.7 , and 1 < 1.7 < 2

Hence, the output is 1.
*/
#include<bits/stdc++.h>
using namespace std;
int triplet(float a[],int n)
{
	if(n<3)
	{
		return 0;
	}
	float a1=a[0];
	float b1=a[1];
	float c1=a[2];
	for(int i=3;i<n;i++)
	{
		if((a1+b1+c1)>1.0 && (a1+b1+c2)<2.0)
		{
			return 1;
		}
		else if((a1+b1+c1)>=2.0)
		{
			return 0;
		}
		else if((a1+b1+c1)<=1.0)
		{
			float n=a[i];
			c1=n;
		}
	}
	if((a1+b1+c1)>1.0 && (a1+b1+c1)<2.0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	float a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	int ans=triplet(a,n);
	cout<<ans<<"\n";
}
