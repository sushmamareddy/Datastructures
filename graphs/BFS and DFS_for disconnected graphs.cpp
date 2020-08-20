#include<bits/stdc++.h>
using namespace std;
void printBFS(int **edges,int sv,int n, bool *visited)
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
void bFS(int **edges,int n)
{
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printBFS(edges,i,n,visited);
		}
	}
	delete []visited;
}
void printDFS(int **edges,int sv,int n, bool *visited)
{
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(i==sv)
		{
			continue;
		}
		if(edges[sv][i]==1)
		{
			if(visited[i])
			{
				continue;
			}
			printDFS(edges,i,n,visited);
		}
	}
}
void dFS(int **edges,int n)
{
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printDFS(edges,i,n,visited);
		}
	}
	delete []visited;
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
	cout<<"DFS : "<<"\n";
	dFS(edges,v);
	cout<<"BFS : "<<"\n";
	bFS(edges,v);
	return 0;
}
