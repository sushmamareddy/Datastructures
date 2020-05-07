/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
*/
#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=target)
            {
                return i;
            }
        }
        return n;
    }
int main()
{
	int n;
	cin>>n;
	int a;
	vector<int>nums;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		nums.push_back(a);	
	}	
	int target;
	cin>>target;
	int ans=searchInsert(nums,target);
	cout<<ans<<"\n";
}
