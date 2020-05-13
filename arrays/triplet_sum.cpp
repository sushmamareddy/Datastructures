/*
Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
Sample Input:
7
1 2 3 4 5 6 7 
12
Sample Output ;
1 4 7
1 5 6
2 3 7
2 4 6
3 4 5
*/
#include<bits/stdc++.h>
using namespace std;
void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        int start=i+1;
        int end=size-1;
        int val=x-arr[i];
        if(arr[start]+arr[end] == val && arr[start]==arr[end])
        {
            int c=(end-start+1);
            int count=(c*(c-1))/2;
            for(int i=0;i<count;i++)
            {
                cout<<arr[i]<<" "<<arr[start]<<" "<<arr[end]<<"\n";
            }
            return;
        }
        while(start<end)
        {
            if(arr[start]+arr[end]>val)
            {
                end--;
            }
            else if(arr[start]+arr[end]<val)
            {
                start++;
            }
            else
            {
                    if(arr[start]==arr[end])
                    {
                        int c=(end-start+1);
                        int count=(c*(c-1))/2;
                        for(int k=0;k<count;k++)
                        {
                            cout<<arr[i]<<" "<<arr[start]<<" "<<arr[end]<<"\n";
                        }
                        start=start+c;
                        end=end-c;
                    }
                    else
                    {
                            int count1=0;
                        int count2=0;
                        for(int k=start;k<=end;k++)
                        {
                            if(arr[k]==arr[start])
                            {
                                count1++;
                            }
                            else
                            {
                                break;
                            }
                        }

                        for(int k=end;k>=start;k--)
                        {
                            if(arr[k]==arr[end])
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
                            cout<<arr[i]<<" "<<arr[start]<<" "<<arr[end]<<"\n";
                        }
                        start=start+count1;
                        end=end-count2;
                	}
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
	FindTriplet(a,n,x);
}
