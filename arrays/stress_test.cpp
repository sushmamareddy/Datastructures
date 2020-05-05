#include<bits/stdc++.h>
using namespace std;
int maxpair(int a[],int n)
{
	int first=INT_MIN;
	int index=-1;
	int second=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>first)
		{
			second=first;
			first=a[i];
			index=i;
		}
		else if(a[i]>=second && i!=index)
		{
			second=a[i];
		}
	}
	return first*second;
}
int main()
{
	/*int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=maxpair(a,n);
	*/
	int t=10;
	while(t--)
	{
		int n=rand()%10+2;
		cout<<n<<endl;
		int a[n];
		for(int i=0;i<n;i++)
		{
			a[i]=rand()%10;
		}
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		int ans=maxpair(a,n);
		cout<<ans<<endl;
	}
	
}
