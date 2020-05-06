/*
You are in an infinite 2D grid where you can move in any of the 8 directions :
 (x,y) to 
    (x+1, y), 
    (x-1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points.
 Give the minimum number of steps in which you can achieve it. You start from the first point.
INPUT(s):
3 0 0 1 
3 0 2 1 

OUTPUT(s):
6
*/
#include<bits/stdc++.h>
using namespace std;
int minsteps(int a[],int b[],int n)
{
	int x1=a[0];
	int y1=b[0];
	int i=1;
	int count=0;
	while(i<n)
	{
		int x2=a[i];
		int y2=b[i];
		int a=max(abs(x2-x1),abs(y2-y1));
		count=count+a;
		x1=x2;
		y1=y2;
		i++;
	}
	return count;
}
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	int ans=minsteps(a,b,n);
	cout<<ans<<"\n";
}
