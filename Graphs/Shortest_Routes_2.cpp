#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
//check once again how floyed warshall works?
signed main()
{
    speed;
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>>dis(n+1,vector<int>(n+1,1e18));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
             dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(dis[a][b]==1e18)dis[a][b]=-1;
        cout<<dis[a][b]<<endl;
    }
    return 0;
}   


