#include<bits/stdc++.h>
using namespace std;
int thirdMax(vector<int>& nums) {
        int first=INT_MIN;
        int second=INT_MIN;
        int third=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>first)
            {
                second=first;
                first=nums[i];
            }
            if(nums[i]>=second && nums[i]!=first)
            {
                second=nums[i];

            }
        }
        //cout<<first<<" "<<second<<"\n";
        int flag=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=third && nums[i]<second)
            {
                third=nums[i];
            }
            if(nums[i]==INT_MIN && second!=INT_MIN)
            {
                flag=0;
            }
        }
        if(flag==0)
        {
            return INT_MIN;
        }

            if(third==INT_MIN)
            {
                return first;
            }
        return third;
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
	int ans=thirdMax(nums);
	cout<<ans<<"\n";
}
