/*
Given a random integer array A and a number x. Find and print the pair of elements in the array which sum to x.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, 5) print "5 6". There is no constraint that out of 5 pairs which have to be printed in 1st line.
 You can print pairs in any order, just be careful about the order of elements in a pair.
Sample Input:
9
1 3 6 2 5 4 3 2 4
7
Sample Output :
1 6
3 4
3 4
2 5
2 5
3 4
3 4
*/
#include<bits/stdc++.h>
using namespace std;
void pairSum(int input[], int size, int x) {
    sort(input,input+size);
    if(input[0]==input[size-1] && input[0]+input[size-1]==x)
    {
        int count=(size * (size-1))/2;
        for(int i=0;i<count;i++)
        {
            cout<<input[0]<<" "<<input[0]<<"\n";
        }
        return;
    }
	unordered_map<int,int>m;
    for(int i=0;i<size;i++)
    {
        m[input[i]]++;
    }
    for(int i=0;i<size;i++)
    {
        int a=x-input[i];
        if(a==input[i])
        {
            int c=m[input[i]];
            int count=(c*(c-1))/2;
            for(int j=0;j<count;j++)
        	{
            	cout<<input[i]<<" "<<input[i]<<"\n";
        	}
            m[input[i]]=0;
            
        }
        else if(m.find(a)!=m.end())
        {
            int count1=m[input[i]];
            int count2=m[a];
            for(int j=0;j<(count1*count2);j++)
            {
                cout<<input[i]<<" "<<a<<"\n";
            }
            m[input[i]]=0;
            m[a]=0;
        }
    }

}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int x;
	cin>>x;
	pairSum(a,n,x);
}
