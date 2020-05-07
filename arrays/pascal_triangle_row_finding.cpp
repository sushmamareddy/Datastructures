/*Given a non-negative index k where k = 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.
Input: 3
Output: [1,3,3,1]
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> getrow(int n)
{
	vector<int>v1;
	vector<int>v2;
	v1.push_back(0);
	for(int i=1;i<=n;i++)
	{
		v1.push_back(0);
	}
	for(int i=1;i<=n+1;i++)
	{
		v2.clear();
		v2.push_back(1);
		for(int j=1;j<i;j++)
		{
			v2.push_back(v1[j]+v1[j-1]);
		}
		v1=v2;
	}
	if(n==0)
	{
		return v1;
	}
	return v2;
}
int main()
{
	int n;
	cin>>n;
	vector<int>ans;
	ans=getrow(n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
