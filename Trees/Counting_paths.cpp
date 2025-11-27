#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n, l,m;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout,val;
vector<vector<int>> up;
void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.resize(n, vector<int>(l + 1));
    dfs(root, root);
}
void go(int node,int par)
{
    for(auto& u : adj[node])
    {
        if(u==par)continue;
        go(u,node);
        val[node]+=val[u];
    }
}
signed main()
{
    speed;
    cin>>n>>m;
   
    val.resize(n,0);
    adj.resize(n,vector<int>(0));
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    preprocess(0);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        --a,--b;
        int LCA=lca(a,b);
        val[a]++;
        val[b]++;
        val[LCA]--;
        if(LCA!=0)val[up[LCA][0]]--;
    }
    go(0,-1);
    for(int i=0;i<n;i++)cout<<val[i]<<" ";
    cout<<endl;
    return 0;
}


