#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,k;
    cout<<"Enter number of items"<<endl;
    cin>>n;
    vector<pair<int,int>>p;
    cout<<"weight and profit"<<endl;
    for(int i=0;i<n;i++){ cin>>a>>b; p.push_back(make_pair(a,b));}
    sort(p.begin(),p.end());
    cout<<"Enter Knapsack capacity:"<<endl;
    cin>>k;
    vector<vector<int>>v(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
    if(j>=p[i-1].first){v[i][j]=max(v[i-1][j],v[i-1][j-p[i-1].first]+p[i-1].second);}
    else if(j<p[i-1].first){v[i][j]=v[i-1][j];}

    cout<<"Maximized Profit is:"<<v[n][k]<<endl;
     return 0;
}
