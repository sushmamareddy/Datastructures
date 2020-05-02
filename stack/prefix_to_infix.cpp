/* 
prefix to infix:
1)scan the input string from left to right
2)if the char is an operand then push it on to the stack
3)if the char is an  operator then pop top two operands from the stack and then apply the operator in between the operands and again push it on to the stack.
	s=(operand operator operand)
4)continue the process for whole string*/
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int l=str.size();
	stack<string>s;
	for(int i=l-1;i>=0;i--)
	{
		if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))
		{
			string s1=string(1,str[i]);
			s.push(s1);
		}
		else
		{
			string a1=s.top();
			s.pop();
			string b1=s.top();
			s.pop();
			string c1="("+a1+str[i]+b1+")";
			s.push(c1);
		}
	}
	string ans=s.top();
	s.pop();
	cout<<ans<<endl;
}
