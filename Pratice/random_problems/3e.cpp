#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n, l,m;
vector<pair<int,int>> adj[200010];
int timer;
vector<int> tin, tout;
vector<vector<int>> up,mx;
struct DSU
{
	int connected;
	vector<int> par, sz;

	void init(int n) 
	{
		par = sz = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}

	int getPar(int u)
	{
		while(u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}

	int getSize(int u)
	{
		return sz[getPar(u)];
	}

	void merge(int u, int v)
	{
		int par1 = getPar(u), par2 = getPar(v);

		if(par1 == par2)
			return;

		connected--;

		if(sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};
void dfs(int v, int p,int w)
{
    tin[v] = ++timer;
    up[v][0] = p;
    mx[v][0] = w;
    for (int i = 1; i <= l; ++i)
    {
        up[v][i] = up[up[v][i-1]][i-1];
        mx[v][i] = max(mx[v][i-1],mx[up[v][i-1]][i-1]);
    }
    for (auto u : adj[v]) {
        if (u.first != p)
            dfs(u.first, v,u.second);
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
int mx_lca(int u, int v)
{
    int ret=-1e18;
    if(up[u][0]==v)return mx[u][0];
    if(up[v][0]==u)return mx[v][0];
    int LCA=lca(u,v);
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
           {
                ret=max(ret,mx[u][i]);
                 u = up[u][i];
           }
    }
    for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[v][i],u))
        {
            ret=max(ret,mx[v][i]);
                v = up[v][i];
        }
    }
    if(up[u][0]==LCA)ret=max(ret,mx[u][0]);
    if(up[v][0]==LCA)ret=max(ret,mx[v][0]);
    return ret;
}
void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l + 1));
    mx.assign(n+1, vector<int>(l + 1));
    dfs(root, root,0);
}
DSU D;
signed main()
{
    speed;
    cin>>n>>m;
    D.init(n);
    vector<pair<int,pair<int,int>>>ed,ed1;
    int cur=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        ed.push_back({w,{u,v}});
    }
    ed1=ed;
    sort(all(ed));
    for(auto& x : ed)
    {
        int u=x.second.first;
        int v=x.second.second;
        int w=x.first;
        if(D.getPar(u)!=D.getPar(v))
        {
            D.merge(u,v);
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            cur+=w;
        }
    }
    assert(D.connected==1);
    preprocess(1);
    for(auto& x : ed1)
    {
        int u=x.second.first;
        int v=x.second.second;
        int w=x.first;
        int sub=mx_lca(u,v);
        cout<<cur+w-sub<<endl;        
    }
    return 0;
}


