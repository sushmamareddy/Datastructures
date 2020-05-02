#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	stack<char>s;
	int flag=1;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='{' || str[i]=='(' || str[i]=='[')
		{
			s.push(str[i]);
			continue;
		}
		else
		{
			if(str[i]=='}')
			{
				if(s.empty())
				{
					flag=0;
					break;
				}
				else
				{
					char t=s.top();
					s.pop();
					if(t=='(' || t=='[')
					{
						flag=0;
						break;
					}
				}
			}
			else if(str[i]==')')
			{
				if(s.empty())
				{
					flag=0;
					break;
				}
				else
				{
					char t=s.top();
					s.pop();
					if(t=='{' || t=='[')
					{
						flag=0;
						break;
					}
				}
			}
			else if(str[i]==']')
			{
				if(s.empty())
				{
					flag=0;
					break;
				}
				else
				{
					char t=s.top();
					s.pop();
					if(t=='(' || t=='{')
					{
						flag=0;
						break;
					}
				}
			}
			
		}
   }	
		if(flag==0 || !s.empty())
		{
			cout<<"unbalanced"<<endl;
		}
		else
		{
			cout<<"balanced"<<endl;
		}
}
