/*
Given an array of integers, sort the array into a wave like array and return it,

In other words, arrange the elements into a sequence such that

a1 >= a2 <= a3 >= a4 <= a5 ...
Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]

NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. So, in example case, you will return [2, 1, 4, 3]
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int i=0;
	int j=1;
	while(i<n && j<n)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i=i+2;
		j=j+2;
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
