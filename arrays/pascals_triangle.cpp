#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows) {
        if(numRows==0)
        {
        vector<vector<int>> ans;
        return ans;
        }
        //for n=1
        if(numRows==1)
        {
        vector<vector<int>> ans(1);
        ans[0].push_back(1);
        return ans;
        }
        //For n>=2 lines
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        ans[1].push_back(1);
        ans[1].push_back(1);
        for(int i=2;i<numRows;i++)
        {
            ans[i].push_back(1);
            for(int j=2;j<=i;j++)
            {
                int temp;
                temp=ans[i-1][j-2]+ans[i-1][j-1];
                ans[i].push_back(temp);
            }
            ans[i].push_back(1);
        }
            
            return ans;
    }
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>ans=generate(n);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
}
