#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,key;
    cin>>n;
    int a[n+10];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int j=1;j<n;j++)
    {
        key=a[j];
        int i=j-1;
        while(i>=0 && a[i]>=key)
        {
            a[i+1]=a[i]; i--;
        }
        a[i+1]=key;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
