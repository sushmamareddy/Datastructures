#include<iostream>
using namespace std;
int main()
{
	int v,e; //v=n of vertices, e= no of edges
	cin>>v>>e;
	int **edges=new int*[v]; //adjacency matrix
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
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<edges[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
}
