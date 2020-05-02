#include<bits/stdc++.h>
using namespace std;
int precedence(char c)
{
	if(c=='*' || c=='/')
	{
		return 2;
	}
	else if(c=='+' || c=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int calculate(char t,int a,int b)
{
	if(t=='+')
		return b+a;
	else if(t=='-')
		return b-a;
	else if(t=='*')
		return b*a;
	else if(t=='/')
		return b/a;
}
int main()
{
	string str;
	cin>>str;
	stack<char>op;
	stack<int>val;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]==' ')
		{
			continue;
		}
		else if(str[i]=='(')
		{
			op.push(str[i]);
		}
		else if(str[i]==')')
		{
			
		}
		else if(isdigit(str[i]))
		{
			int v = 0;  
            while(i < str.length() &&  
                        isdigit(str[i])) 
            { 
                v = (v*10) + (str[i]-'0'); 
                i++; 
            } 
            cout<<v<<endl;
            val.push(v); 
		}
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
		{
			if(op.empty())
			{
				cout<<str[i]<<endl;
				op.push(str[i]);
			}
			else
			{
				if(!op.empty() && precedence(op.top())<precedence(str[i]))
				{
					cout<<str[i]<<endl;
					op.push(str[i]);
				}
				else
				{
					
				}
			}
			
		}
	}
	while(!op.empty())
	{
		char t=op.top();
		cout<<t<<" ";
		op.pop();
		int a=val.top();
		val.pop();
		int b=val.top();
		val.pop();
		int ans=calculate(t,a,b);
		val.push(ans);
	}
	return val.top();
}
