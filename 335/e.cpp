#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
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
DSU D;
const int maxn=2e5+5;
int n,m;
vector<int>a,dist;
vector<int>gp[maxn];
vector<pair<int,int>>edges;
void bfs(int n)
{
    set<pair<int,int>>st;
    st.insert({a[n],n});
    dist[n]=1;
    while(sz(st))
    {
        int val=st.begin()->first;
        int node=st.begin()->second;
        st.erase(st.begin());
        for(auto& u : gp[node])
        {
            if(dist[u]<dist[node]+1)
            {
                dist[u]=dist[node]+1;
                st.insert({a[u],u});
            }
        }
    }
}
bool cmp(int& x, int& y)
{
    return a[x]<a[y];
}
signed main()
{
    speed;
    cin>>n>>m;
    a.resize(n+1);
    dist.resize(n+1,-1e18);
    for(int i=1;i<=n;i++)cin>>a[i];
    D.init(n);
    while(m--)
    {
        int u,v;cin>>u>>v;
        if(a[u]==a[v])D.merge(u,v);
        edges.push_back({u,v});
    }
    for(auto& u : edges)
    {
        int x=D.getPar(u.first);
        int y=D.getPar(u.second);
        if(x!=y)
        {
            if(a[x]<a[y])
            gp[x].push_back(y);
            else gp[y].push_back(x);
        }
    }
    // for(int i=1;i<=n;i++)sort(all(gp[i]),cmp);
    bfs(D.getPar(1));
    int ans=dist[D.getPar(n)];
    if(ans<0)ans=0;
    cout<<ans<<endl;
    return 0;
}
