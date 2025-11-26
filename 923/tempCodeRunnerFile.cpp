#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<vector<int>>gp;
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
vector<int>par,vis;
void dfs(int n,int p)
{
    par[n]=p;
    vis[n]=1;
    for(auto& u : gp[n])
    {
        if(!vis[u])
        dfs(u,n);
    }
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        gp.resize(n+1);
        DSU D;
        D.init(n);
        gp.resize(n+1);
        vector<pair<int,pair<int,int>>>edges;
        while(m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            gp[u].push_back(v);
            gp[v].push_back(u);
            edges.push_back({w,{u,v}});
        }
        sort(all(edges));
        reverse(all(edges));
        int best=1e18;
        int x=-1,y=-1;
        for(auto& u : edges)
        {
            if(D.getPar(u.second.first)!=D.getPar(u.second.second))
            {
                D.merge(u.second.first,u.second.second);
            }
            else 
            {
                best=min(best,u.first);
                x=u.second.first;
                y=u.second.second;
            }
        }
        par.resize(n+1,0);  
        vis.resize(n+1,0);
        dfs(x,0);
        int cur=y;
        vector<int>nodes;
        while(cur!=0)
        {
            nodes.push_back(cur);
            cur=par[cur];
        }
        cout<<best<<" "<<nodes.size()<<endl;
        for(auto& u : nodes)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


