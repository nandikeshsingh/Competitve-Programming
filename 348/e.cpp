#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n;
vector<int>c;
vector<vector<int>>gp;
vector<int>sub;
vector<int>cur;
int ans;
int tot;
void dfs1(int node,int par,int d)
{
    cur[0]+=c[node]*d;
    for(auto& u : gp[node])
    {
        if(u==par)continue;
        dfs1(u,node,d+1);
        sub[node]+=sub[u];
    }
    sub[node]+=c[node];
}
void dfs(int node,int par)
{
    if(node!=0)
    {
        cur[node]=cur[par]-sub[node]+tot-sub[node];
        ans=min(ans,cur[node]);
    }
    for(auto& u : gp[node])
    {
        if(u==par)continue;
        dfs(u,node);
    }
}
signed main()
{
    speed;
    cin>>n;
    c.resize(n);
    sub.resize(n);
    gp.resize(n);
    cur.resize(n);
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        u--;v--;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    for(int i=0;i<n;i++)cin>>c[i],tot+=c[i];
    dfs1(0,-1,0);
    ans=cur[0];
    dfs(0,-1);
    cout<<ans<<endl;
    return 0;
}


