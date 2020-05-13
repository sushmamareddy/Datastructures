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
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    sort(input,input+size);
    int i=0;
    int j=size-1;
    if(input[i]+input[j]==x && input[i]==input[j])
    {
        int count=(size*(size-1))/2;
        for(int i=0;i<count;i++)
        {
            cout<<input[i]<<" "<<input[j]<<"\n";
        }
        return;
    }
    while(i<j)
    {
        if(input[i]+input[j] < x)
        {
            i++;
        }
        else if(input[i]+input[j] > x)
        {
            j--;
        }
        else
        {
        	if(input[i]==input[j])
            {
                int c=(j-i+1);
                int count=(c*(c-1))/2;
                for(int k=0;k<count;k++)
                {
                    cout<<input[i]<<" "<<input[j]<<"\n";
                }
                i=i+c;
                j=j-c;
            }
            else
            {
                int count1=0;
                int count2=0;
                for(int k=i;k<=j;k++)
                {
                    if(input[k]==input[i])
                    {
                        count1++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                for(int k=j;k>=i;k--)
                {
                    if(input[k]==input[j])
                    {
                        count2++;
                    }
                    else
                    {
                        break;
                    }
                }
                int count=count1*count2;
                for(int k=0;k<count;k++)
                {
                    cout<<input[i]<<" "<<input[j]<<"\n";
                }
                i=i+count1;
                j=j-count2;
            }
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
