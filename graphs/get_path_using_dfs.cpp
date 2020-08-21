#include<bits/stdc++.h>
using namespace std;
void getpath(int **edges,int v, int start,int finish,bool *visited,vector<int>&ans)
{
	visited[start]=true;
	if(start==finish)
	{
		ans.push_back(start);
		return;
	}
	for(int i=0;i<v;i++)
	{
		if(i==start)
		{
			continue;
		}
		if(edges[start][i]==1)
		{
			if(visited[i])
			{
				continue;
			}
			else
			{
				getpath(edges,v,i,finish,visited,ans);
				if(!ans.empty())
				{
					ans.push_back(start);
					return;
				}
			}
		}
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	int **edges = new int *[v];
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
	int start,finish;
	cin>>start>>finish;
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	vector<int>ans;
	getpath(edges,v,start,finish,visited,ans);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
