#include<bits/stdc++.h>
using namespace std;
bool  check(string str)
{
	stack<char>s;
	int l=str.size();
	int c;
	for(int i=0;i<l;i++)
	{
		if(str[i]==')')
		{
			c=0;
			while(s.top()!='(')
			{
				s.pop();
				c++;
			}
			if(s.top()=='(')
			{
				s.pop();
			}
			if(c==0)
			{
				break;
			}
		}
		else
		{
			s.push(str[i]);
		}
	}
	if(c==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	string str;
	cin>>str;
	bool ans=check(str);
	if(ans==0)
	{
		cout<<"no"<<endl;
	}
	else
	{
		cout<<"yes"<<endl;
	}
}
