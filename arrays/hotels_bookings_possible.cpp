/*
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date.
 He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N).
 
 Example :

Input :

        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1
Return :

False / 0 
At day = 5, there are 2 guests in the hotel. But I have only one room.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n],dep[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>dep[i];
	}
	sort(arr,arr+n);
	sort(dep,dep+n);
	int k;
	cin>>k;
	int i=0,j=0,c=0;
	while(i<n && j<n)
	{
		if(arr[i]<dep[j])
		{
			i++;
			c++;
		}
		else
		{
			j++;
			c--;
		}
		if(c>k)
		{
			cout<<"False\n";
			return 0;
		}
	}
	cout<<"True\n";
}
