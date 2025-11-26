#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int INF=1e18;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>gp(n+1,vector<int>(n+1,1e18));
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if(gp[u][v]==1e18)
            {
                gp[u][v]=w;
                gp[v][u]=w;
            }
            else 
            {
                gp[u][v]=min(gp[u][v],w);
                gp[v][u]=min(gp[v][u],w);
            }
        }
        for (int k = 1; k <= n; ++k) 
        {
            for (int i = 1; i <= n; ++i) 
            {
                for (int j = 1; j <= n; ++j) 
                {
                        if (gp[i][k] < INF && gp[k][j] < INF)
                            {
                                // if(gp[i][k] + gp[k][j]>=2*gp[i][k])
                                gp[i][j] = min(gp[i][j], min(gp[i][k] + gp[k][j],2*gp[i][k])); 
                            }
                }
            }
        }
                for (int k = 1; k <= n; ++k) 
        {
            for (int i = 1; i <= n; ++i) 
            {
                for (int j = 1; j <= n; ++j) 
                {
                        if (gp[i][k] < INF && gp[k][j] < INF)
                            {

                                gp[i][j] = min(gp[i][j],gp[i][k] + gp[k][j]); 
                            }
                }
            }
        }
        cout<<gp[1][n]<<endl;
    }
    return 0;
}


