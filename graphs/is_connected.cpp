#include<bits/stdc++.h>
using namespace std;
void isconnected(int **edges,int sv,int v,bool *visited)
{
	stack<int>s;
	s.push(sv);
	visited[sv]=true;
	while(!s.empty())
	{
		int front = s.top();
		s.pop();
		for(int i=0;i<v;i++)
		{
			if(i==front)
			{
				continue;
			}
			else
			{
				if(edges[front][i]==1 && !visited[i])
				{
					s.push(i);
					visited[i]=true;
				}
			}
		}
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	int **edges = new int * [v];
	for(int i=0;i<v;i++)
	{
		edges[i]=new int[v];
		for(int j=0;j<v;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>s>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	isconnected(edges,0,v,visited);
	int flag=1;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"connected \n";
	}
	else
	{
		cout<<"not connected\n";
	}
}
