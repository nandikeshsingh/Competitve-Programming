#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n;
vector<vector<int>>gp;
vector<int>val,sub,p;
void dfs(int node,int par)
{
    p[node]=par;
    for(auto u : gp[node])
    {
        if(u==par)continue;
        dfs(u,node);
        val[node]+=(val[u]+sub[u]);
        sub[node]+=sub[u];
    }
    sub[node]+=1;
}
void dfs1(int node,int par)
{
    for(auto & u : gp[node])
    {
        if(par==u)continue;
        val[u]=val[u]+(val[node]-val[u]-sub[u])+n-sub[u];
        dfs1(u,node);
    }
}
signed main()
{
    speed;
    cin>>n;
    gp.resize(n+1,vector<int>(0));
    val.resize(n+1);
    sub.resize(n+1);
    p.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    dfs(1,-1);
    dfs1(1,-1);
    for(int i=1;i<=n;i++)
    {
        cout<<val[i]<<" ";
    }
    cout<<endl;
    return 0;
}


