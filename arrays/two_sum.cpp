/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> twosum(int a[],int n,int target)
{
	int i=0;
	int j=n-1;
	vector<int>ans;
	while(i<j)
	{
		if(a[i]+a[j]==target)
		{
			ans.push_back(i+1);
			ans.push_back(j+1);
			break;
		}
		else if(a[i]+a[j] < target)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return ans;
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
	int target;
	cin>>target;
	vector<int>ans=twosum(a,n,target);
	cout<<ans[0]<<" "<<ans[1]<<"\n";
}
