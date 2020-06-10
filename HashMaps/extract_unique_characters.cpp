#include<bits/stdc++.h>
using namespace std;
string unique(string s)
{
	int n=s.size();
	unordered_map<char,bool>m;
	string ans="";
	for(int i=0;i<n;i++)
	{
		if(m.count(s[i])>0)
		{
			continue;
		}
		m[s[i]]=true;
		ans=ans+s[i];
	}
	return ans;
}
int main()
{
	string s;
	cin>>s;
	string ans=unique(s);
	cout<<ans<<"\n";
}
