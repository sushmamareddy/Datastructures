#include<bits/stdc++.h>
using namespace std;
void getpath(int **edges,int v,int v1,int v2,bool *visited)
{
	queue<int>q;
	map<int,int>m;
	bool found=false;
	q.push(v1);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		if(f==v2)
		{
			found=true;
			break;
		}
		for(int i=0;i<v;i++)
		{
			if(i==f)
			{
				continue;
			}
			else
			{
				if(edges[f][i]==1 && !visited[i])
				{
					q.push(i);
					visited[i]=true;
					m[i]=f;
				}
			}
		}
	}
	if(found)
	{
		int a=v2;
		while(a!=v1)
		{
			cout<<a<<" ";
			a=m[a];
		}
		cout<<v1<<" ";
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
		int s,f;
		cin>>s>>f;
		edges[s][f]=1;
		edges[f][s]=1;
	}
	int start,finish;
	cin>>start>>finish;
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	getpath(edges,v,start,finish,visited);
}
