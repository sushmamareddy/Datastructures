#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
void dfs(int **edges,int v,int sv, bool *visited)
{
	vec.push_back(sv);
	visited[sv]=true;
	for(int i=0;i<v;i++)
	{
		if(i==sv)
		{
			continue;
		}
		else
		{
			if(edges[sv][i]==1)
			{
				if(visited[i])
				{
					continue;
				}
				else
				{
					dfs(edges,v,i,visited);
				}
			}
		}
	}
}
void connected(int **edges,int v)
{
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			dfs(edges,v,i,visited);
			sort(vec.begin(),vec.end());
			for(int i=0;i<vec.size();i++)
			{
				cout<<vec[i]<<" ";
			}
			vec.clear();
			cout<<"\n";
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
	connected(edges,v);
}
