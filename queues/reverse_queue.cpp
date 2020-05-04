#include<bits/stdc++.h>
using namespace std;
int main()
{
	queue<int>q;
	for(int i=1;i<=10;i++)
	{
		q.push(i);
	}
	stack<int>s;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		s.push(t);
	}
	while(!s.empty())
	{
		int t=s.top();
		s.pop();
		q.push(t);
	}
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		cout<<t<<" ";
	}
	cout<<"\n";
}
