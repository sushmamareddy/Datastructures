#include<bits/stdc++.h>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    unordered_map<int,bool>m;
    unordered_map<int,int>m2;
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        m2[arr[i]]=i;
        m[arr[i]]=true;
    }
    int curlength=1;
    int maxlength=1;
    int curstart=arr[0];
    int maxstart=arr[0];
    for(int i=0;i<n;i++)
    {
        if(m[arr[i]]==true)
        {
            curstart=arr[i];
            int j=arr[i]+1;
            while(j)
            {
                if(m.find(j)!=m.end())
                {
                    m[j]=false;
                    curlength++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            j=arr[i]-1;
            while(j>=0)
            {
                if(m.find(j)!=m.end())
                {
                    m[j]=false;
                    curlength++;
                    curstart=j;
                    j--;
                }
                else
                {
                    break;
                }
            }
            m[arr[i]]=false;
            if(curlength==maxlength)
            {
                if(m2[curstart] < m2[maxstart])
                {
                    maxlength=curlength;
                	maxstart=curstart;
                }
            }
            else if(curlength>maxlength)
            {
                maxlength=curlength;
                maxstart=curstart;
            }
            curlength=1;
            curstart=0;
        }  
    }
    for(int i=maxstart;i<maxstart+maxlength;i++)
    {
        ans.push_back(i);
    }
    return ans;
}
int main()
{
	int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}
