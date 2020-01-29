#include <bits/stdc++.h>
using namespace std;
int partition1(int a[],int low,int high)
{
    int x=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
int quicksort(int a[],int low,int high)
{
   if(low<high)
   {
       int q=partition1(a,low,high);
       quicksort(a,low,q-1);
       quicksort(a,q+1,high);
   }
}
int binarysearch(int a[],int low,int high,int p)
{
    if(low<=high)
    {
        int mid=(high+low)/2;
        if(p==a[mid])return mid;
        else if(p<=a[mid])return binarysearch(a,low,mid-1,p);
        else return binarysearch(a,mid+1,high,p);
    }
    return -1;
}
int main()
{
    int n,p;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    quicksort(a,0,n-1);
     cout<<"Enter the number to find"<<endl;
    cin>>p;
    if(binarysearch(a,0,n-1,p)!=-1) cout<<"element found at position:"<<binarysearch(a,0,n-1,p)+1<<endl;
    else cout<<"Element Not found"<<endl;


    return 0;
}
