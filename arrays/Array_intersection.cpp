/*
Given two random integer arrays, print their intersection. 
That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2 
4 
3
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 
2
1
*/
#include<bits/stdc++.h>
using namespace std;
void intersection(int a[],int n1,int b[],int n2)
{
	sort(a,a+n1);
	sort(b,b+n2);
	int i=0;
	int j=0;
	while(i<n1 && j<n2)
	{
		if(a[i]==b[j])
		{
			cout<<a[i]<<"\n";
			i++;
			j++;
		}
		else if(a[i]<b[j])
		{
			i++;
		}
		else 
		{
			j++;
		}
	}
}
int main()
{
	int n1;
	cin>>n1;
	int a[n1];
	for(int i=0;i<n1;i++)
	{
		cin>>a[i];
	}
	int n2;
	cin>>n2;
	int b[n2];
	for(int i=0;i<n2;i++)
	{
		cin>>b[i];
	}
	intersection(a,n1,b,n2);
}
