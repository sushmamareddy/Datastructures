/*
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid substring.

NOTE: Length of smallest the valid substring ( ) is 2.
For Input:
2
))))))()()))(())))())((()()()())(((()))())
)()()()))((((()()())(()()())(())((
Your Output is:
20
20*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	stack<int>s;
	s.push(-1);
	int result=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='(')
		{
			s.push(i);
		}
		else
		{
			s.pop();
			if(!s.empty())
			{
				result=max(result,i-s.top());
			}
			else
			{
				s.push(i);
			}
		}
	}
	cout<<result<<endl;
}
