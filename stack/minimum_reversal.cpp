#include<bits/stdc++.h>
using namespace std;
int minimum(string str)
{
	stack<char>s;
	int l=str.size();
	if(l%2!=0)
	{
		return -1;
	}
	int count=0;
	for(int i=0;i<l;i++)
	{
		if(str[i]=='{')
		{
			s.push(str[i]);
		}
		else
		{
			if(s.empty())
			{
				s.push(str[i]);
			}
			else if(s.top()=='}')
			{
				s.push(str[i]);
			}
			else
			{
				s.pop();
			}
		}
	}
	while(!s.empty())
	{
		char a=s.top();
		s.pop();
		char b=s.top();
		s.pop();
		if(a==b)
		{
			count=count+1;
		}
		else
		{
			count=count+2;
		}
	}
	return count;
}
int main()
{
	string str;
	cin>>str;
	int ans=minimum(str);
	cout<<ans<<endl;
}
