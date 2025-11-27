#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n;
vector<vector<int>>gp;
vector<int>dis;
void dfs(int node,int p,int d)
{
    dis[node]=d;
    for(auto u : gp[node])
    {
        if(u==p)continue;
        dfs(u,node,d+1);
    }
}
signed main()
{
    speed;
    cin>>n;
    gp.resize(n+1,vector<int>(0));
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    dis.resize(n+1);
    dfs(1,-1,0);
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[pos]<dis[i])pos=i;
    }
    for(int i=1;i<=n;i++)dis[i]=0;
    dfs(pos,-1,0);
    int pos2=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[pos2]<dis[i])pos2=i;
    }
    vector<int>dis1=dis;
    for(int i=1;i<=n;i++)dis[i]=0;
    dfs(pos2,-1,0);
    for(int i=1;i<=n;i++)
    cout<<max(dis[i],dis1[i])<<" ";
    cout<<endl;
    return 0;
}


