#include<bits/stdc++.h>
using namespace std;
void dfs(int **edges,int sv,int n,bool *visited)
{
	stack<int>s1;
	s1.push(sv);
	while(!s1.empty())
	{
		int s=s1.top();
		s1.pop();
		if(!visited[s])
		{
			cout<<s<<" ";
			visited[s]= true;
		}
		for(int i=0;i<n;i++)
		{
			if(i==s)
			{
				continue;
			}
			if(edges[s][i]==1)
			{
				if(!visited[i])
				{
					s1.push(i);
				}
			}
		}
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	int **edges = new int*[v];
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
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	dfs(edges,0,v,visited);
}
