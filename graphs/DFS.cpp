#include<bits/stdc++.h>
using namespace std;
void dfs(int **edges,int sv,int v,bool *visited)
{
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<v;i++)
	{
		if(i==sv)
		{
			continue;
		}
		for(int i=0;i<v;i++)
		{
			if(edges[sv][i]==1)
			{
				if(visited[i]==true)
				{
					continue;
				}
				dfs(edges,i,v,visited);
			}
		}
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	int **edges=new int*[v];
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
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	dfs(edges,0,v,visited);

}
