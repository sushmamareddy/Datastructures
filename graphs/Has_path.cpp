/*Given an undirected graph G(V,E) and two vertices v1 and v2,check if there exists any path between them or not.print true or false.
i/p : 4 4
	  0 1
	  0 3
	  1 2
	  2 3
	  1 3
o/p: true

*/
#include<bits/stdc++.h>
using namespace std;
bool HasPath(int **edges,int n,int s,int f,bool *visited)
{
	queue<int>q;
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		if(front==f)
		{
			return true;
		}
		for(int i=0;i<n;i++)
		{
			if(i==front)
			{
				continue;
			}
			if(edges[front][i]==1 && !visited[i])
			{
				q.push(i);
				visited[i]=true;
			}
		}
	}
	return false;
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
	int start,finish;
	cin>>start>>finish;
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	
	bool ans = HasPath(edges,v,start,finish,visited);
	if(ans)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}
