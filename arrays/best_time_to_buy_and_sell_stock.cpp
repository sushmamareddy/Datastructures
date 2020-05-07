/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
*/
#include<bits/stdc++.h>
using namespace std;
int maxprofit(int a[],int n)
{
	int max=0;
	int profit=0;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		int temp=max-a[i];
		if(temp>profit)
		{
			profit=temp;
		}
	}
	return profit;
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
	int ans=maxprofit(a,n);
	cout<<ans<<"\n";
}
