#include <bits/stdc++.h>
using namespace std;
int n,a;
int djkstra(vector<vector<int>>v,int src)
{
    int in;
    bool visit[n+20];
    int d[n+20];
    for(int i=0;i<n;i++)
    {
      d[i]=INT_MAX;
      visit[i]=0;
    }
    d[0]=0;

    for(int i=0;i<n;i++)
    {
        int mi=INT_MAX;
      for(int j=0;j<n;j++)
      {
          if(visit[j]==0 && d[j]<=mi)
          {
            mi=d[j];
            in=j;
          }
      }
      visit[in]=1;
      for(int j=0;j<n;j++)
      {
        if(d[in]+v[in][j]<d[j] && !visit[j] && v[in][j] && d[in]!=INT_MAX)
        {
            d[j]=d[in]+v[in][j];
        }
      }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"th node"<<" "<<d[i]<<endl;
    }
}

int main()
{
    cout<<"No. of nodes:";
    cin>>n;
    vector<vector<int>>v(n+20);
    vector<vector<int>>e(n+20);
    for(int i=0;i<n;i++)
    {
     v.push_back(vector<int>());
     for(int j=0;j<n;j++)
     {
      cin>>a;
      v[i].push_back(a);
     }
    }
    int c;
    cout<<"Enter your choice:"<<endl;
    cout<<"1.Djkstra"<<endl;
    cout<<"2.Bellman ford"<<endl;
    cin>>c;
    if(c==1)djkstra(v,0);
    else
    {
    int visit[n+20];
    int k=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(v[i][j]!=0){e[k][0]=i;e[k][1]=j;k++;}

  int d[n+20],flag=1;
    for(int i=0;i<n;i++){d[i]=INT_MAX;visit[i]=-1;}
        int src=0;
        d[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<k;j++)
        {
            //int u = e[j][0];
            //int v = e[j][1];
            if(d[e[j][0]]+v[e[j][0]][e[j][1]] < d[e[j][1]])d[e[j][1]] = d[e[j][0]] + v[e[j][0]][e[j][1]];
            visit[e[j][1]]=e[j][0] ;
        }
    }
    for(int j=0;j<k;j++)
        {
            int a = e[j][0];
            int b = e[j][1] ;
            
            if(d[a]+v[a][b]<d[b])flag=0;
        }
        if(flag==1)for(int i=0;i<n;i++)cout<<i<<" "<<d[i];

        return flag;

    }


    return 0;
}

