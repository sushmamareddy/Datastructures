#include<bits/stdc++.h>
using namespace std;
int precedence(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='*' || c=='/' || c=='%')
	{
		return 2;
	}
	else if(c=='+' || c=='-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	string str;
	cin>>str;
	stack<char>s;
	int l=str.size();
	string ans="";
	for(int i=l-1;i>=0;i--)
	{
		if((str[i]>='a' && str[i]<='z') ||(str[i]>='A' && str[i]<='Z'))
		{
			ans=str[i]+ans;
		}
		else
		{
			if(str[i]==')')
			{
				s.push(str[i]);
			}
			else if(str[i]=='(')
			{
				while(!s.empty() && s.top()!=')')
				{
					char t=s.top();
					s.pop();
					ans=t+ans;
				}
				if(s.top()==')')
				{
					s.pop();
				}
			}
			else
			{
				while(!s.empty() && precedence(s.top())>=precedence(str[i]))
				{
					char t=s.top();
					s.pop();
					ans=t+ans;
				}
				s.push(str[i]);
			}
		}
	}
	while(!s.empty())
	{
		char t=s.top();
		s.pop();
		ans=t+ans;
	}
	cout<<ans<<endl;
}
