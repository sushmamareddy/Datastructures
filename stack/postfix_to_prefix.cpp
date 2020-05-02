#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int l=str.size();
	stack<string>s;
	for(int i=0;i<l;i++)
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
			string c1=str[i]+b1+a1;
			s.push(c1);
		}
	}
	string ans=s.top();
	s.pop();
	cout<<ans<<endl;
}
