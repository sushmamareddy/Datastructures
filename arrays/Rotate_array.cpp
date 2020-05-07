#include<bits/stdc++.h>
using namespace std;
void reverse(int a[],int start,int end)
{
	int low=start;
	int high=end-1;
	while(low<=high)
	{
		swap(a[low],a[high]);
		low++;
		high--;
	}
}
void rotate(int a[],int n,int k)
{
	k=k%n;
	reverse(a,0,n);
	reverse(a,0,k);
	reverse(a,k,n);
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
	int k;
	cin>>k;
	rotate(a,n,k);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
