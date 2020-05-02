#include<bits/stdc++.h>
using namespace std;
void sortstack(stack<int>&s1,stack<int>&s2)
{
	
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
	sortstack(s1,s2);
	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
	
}
