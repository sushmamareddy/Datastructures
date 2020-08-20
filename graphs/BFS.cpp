#include<bits/stdc++.h>
using namespace std;
void bfs(int **edges,int sv,int n,bool *visited)
{
	queue<int>q;
	q.push(sv);
	visited[sv]=true;
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		cout<<s<<" ";
		for(int i=0;i<n;i++)
		{
			if(i==s)
			{
				continue;
			}
			if(edges[s][i]==1 && !visited[i])
			{
				q.push(i);
				visited[i]=true;
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
	bfs(edges,0,v,visited);
}
