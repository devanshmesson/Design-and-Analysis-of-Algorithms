#include <iostream>
using namespace std;
maximum_sum_array(int a[],int low,int high)
{
    if(low==high)return a[low];
    else
    {
        int mid=(low+high)/2;
        int left_sum=INT_MIN;
        int sum=0;
        for(int i=mid;i>=low;i--)
        {
            sum+=a[i];
            if(sum>left_sum)left_sum=sum;
        }
        int right_sum=INT_MIN;
        sum=0;
        for(int i=mid+1;i<=high;i++)
        {
            sum+=a[i];
            if(sum>right_sum)right_sum=sum;
        }

       int max_left_right=max(maximum_sum_array(a,low,mid),maximum_sum_array(a,mid+1,high));
        int ans=max(max_left_right,left_sum+right_sum);
        return ans;
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
   int p=maximum_sum_array(a,0,n-1);
   cout<<p<<endl;
      return 0;
}
