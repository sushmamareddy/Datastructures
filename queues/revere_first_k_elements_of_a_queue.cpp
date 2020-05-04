#include<bits/stdc++.h>
using namespace std;
int main()
{
	queue<int>q;
	for(int i=1;i<=10;i++)
	{
		q.push(i);
	}
	int k=5;
	stack<int>s;
	int c=0;
	while(c<k && !q.empty())
	{
		int t=q.front();
		q.pop();
		s.push(t);
		c++;
	}
	queue<int>ans;
	while(!s.empty())
	{
		int t=s.top();
		s.pop();
		ans.push(t);
	}
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		ans.push(t);	
	}
	while(!ans.empty())
	{
		int t=ans.front();
		ans.pop();
		cout<<t<<" ";
	}
	cout<<endl;
}
