/*
Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.use only stack*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	queue<int>q;
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		q.push(a);
	}
	int c=0;
	while(c<n/2 && !q.empty())
	{
		s.push(q.front());
		q.pop();
		c++;
	}
	c=0;
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	while(c<n/2 && !q.empty())
	{
		q.push(q.front());
		q.pop();
		c++;
	}
	c=0;
	while(c<n/2 && !q.empty())
	{
		s.push(q.front());
		q.pop();
		c++;
	}
	while(!s.empty() && !q.empty())
	{
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}
