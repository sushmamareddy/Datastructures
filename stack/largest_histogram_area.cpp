#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int>s;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int maxarea=0,curarea;
	int i=0;
	while(i<n)
	{
		if(s.empty() || a[s.top()]<=a[i])
		{
			s.push(i);
			i++;
		}
		else
		{
			int t=s.top();
			s.pop();
			if(s.empty())
			{
				curarea=a[t]*i;
			}
			else
			{
				curarea=a[t]*(i-s.top()-1);
			}
			if(curarea>=maxarea)
			{
				maxarea=curarea;
			}
		}
	}
	while(!s.empty())
    {
        int t=s.top();
            s.pop();
            if(s.empty())
            {
                curarea=a[t]*i;
            }
            else {
                curarea=a[t]*(i-s.top()-1);
            }
            if(curarea>maxarea)
            {
                maxarea=curarea;
            }
    }
	cout<<maxarea<<endl;
}
