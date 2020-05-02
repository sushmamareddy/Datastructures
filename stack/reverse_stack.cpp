#include<bits/stdc++.h>
using namespace std;
void reversestack(stack<int>&s1,stack<int>&s2)
{
	int l=s1.size();
	if(l==0 || l==1)
	{
		return;
	}
	int x=s1.top();
	s1.pop();
	reversestack(s1,s2);
	while(!s1.empty())
	{
		int s=s1.top();
		s1.pop();
		s2.push(s);
	}
	s1.push(x);
	while(!s2.empty())
	{
		int s=s2.top();
		s2.pop();
		s1.push(s);
	}
}
int main()
{
	stack<int>s1,s2;
	int size;
	cin>>size;
	int val;
	for(int i=0;i<size;i++)
	{
		cin>>val;
		s1.push(val);
	}
	reversestack(s1,s2);
	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
}
