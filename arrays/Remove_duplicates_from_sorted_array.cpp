/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>&nums)
{
	int i=0;
	int j=1;
	while(j<nums.size())
	{
		if(nums[i]==nums[j])
		{
			j++;
		}
		else
		{
			i++;
			nums[i]=nums[j];
		}
	}
	return i+1;
}
int main()
{
	int n;
	cin>>n;
	vector<int>nums;
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		nums.push_back(a);
	}
	int len = removeDuplicates(nums);
	for (int i = 0; i < len; i++) {
    	cout<<nums[i]<<" ";
	}
}
