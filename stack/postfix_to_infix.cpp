#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	stack<string>s;
	for(int i=0;i<str.size();i++)
	{
		if((str[i]>='a' && str[i]<='z')|| (str[i]>='A' && str[i]<='Z'))
		{
			s.push(string(1,str[i]));
		}
		else
		{
			string a1=s.top();
			s.pop();
			string b1=s.top();
			s.pop();
			string c1="("+b1+str[i]+a1+")";
			s.push(c1);
		}
	}
	string ans=s.top();
	s.pop();
	cout<<ans<<endl;
}
