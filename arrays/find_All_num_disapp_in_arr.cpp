/*
Given an array of integers where 1 = a[i] = n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

*/
#include<bits/stdc++.h>
using namespace std;
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         for (int  i = 0; i < nums.size();i++) {
        int j = abs(nums[i]) - 1;
        nums[j] = abs(nums[j]) * -1;
    }
    
    vector<int>ans;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            ans.push_back(i + 1);
        }
    }
    
    return ans;
    }
int main()
{
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	vector<int>ans=findDisappearedNumbers(nums);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
