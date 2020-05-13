#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int n;
int part(int a[],int low,int pivot)
{
    int i=low-1;
    for(int j=low;j<=pivot-1;j++)
    {
       if(a[j]<=a[pivot])
       {
           i++;
           swap(a[j],a[i]);
       }
    }
    swap(a[i+1],a[pivot]);
    return i+1;
}
int quicksort(int a[],int low ,int high)
{
    if(low<high)
     {
            int j=part(a,low,high);
            quicksort(a,low,j-1);
            quicksort(a,j+1,high);
     }
}
int32_t main()
{
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
